import fs from "fs";
import json from "./schema.json";

type Key = keyof NonNullable<typeof json.examples[0]>;
Object.entries(json.properties).forEach(([key, value]) => {
  const { properties } = value;
  const example = json.examples[0]?.[key as Key];
  if (example === undefined) throw new Error("undefined example");
  const parameters = Object.entries(properties).map(([key, value]) => {
    type V = typeof value;
    const {
      $id,
      title,
      examples,
      description,
      type,
      $ref,
      ...rest
    } = value as {
      $id: V["$id"];
      title: V["title"];
      examples: string[];
      description: string;
      type: any;
      $ref: any;
    };

    const returnData = {
      in: "query",
      name: key,
      examples: (() => {
        if (examples !== undefined) {
          return Object.fromEntries(
            examples.map((value, i) => {
              if (i === 0) {
                return {
                  default: {
                    value,
                    summary: "default",
                  },
                };
              }
              return {
                [value]: {
                  value,
                  summary: value,
                },
              };
            }) as any[]
          );
        }
        return {
          default: {
            value: (example as any)[key],
            summary: "default",
          },
        };
      })(),
      description: description ?? title,
      ...rest,
    };
    if (type !== undefined) {
      Object.assign(returnData, {
        schema: {
          type: Array.isArray(type) ? type[0] : type,
        },
      });
    }
    if ($ref !== undefined) {
      Object.assign(returnData, {
        schema: {
          $ref,
        },
      });
    }
    return returnData;
  });

  const writeData = {
    parameters,
  };

  fs.writeFileSync("wip.json", JSON.stringify(writeData, null, "  "));
});
