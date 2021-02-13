import Ajv from "ajv";
import schema from "./schema.json";
import validateTarget from "./data.json";

function main(): number {
    const ajv = new Ajv();

    const validate = ajv.compile(schema);

    const result = validate(validateTarget);

    if (!result) {
        validate.errors?.forEach((error) => {
            console.log(error);
        });
        return 1;
    }
    process.stdout.write(`valid\n`);
    return 0;
}

main();