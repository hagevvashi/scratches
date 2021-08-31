const commandLineArgs = require("command-line-args");

const optionDefinitions = [
  {
    name: "verbose",
    alias: "v",
    type: Boolean,
  },
  {
    name: "src",
    type: String,
  },
  {
    name: "timeout",
    alias: "t",
    type: Number,
    defaultValue: 3,
  },
];
const options = commandLineArgs(optionDefinitions);

console.log(options);
