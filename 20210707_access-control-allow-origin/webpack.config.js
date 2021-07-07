const path = require("path");
const webpack = require("webpack");
const HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = {
  mode: "production",
  entry: {
    main: "./src/index.js",
  },
  output: {
    path: path.resolve(__dirname, "./dist"),
    filename: "[name].js",
    clean: true,
  },
  plugins: [
    new webpack.EnvironmentPlugin(["URL"]),
    new HtmlWebpackPlugin({
      template: "src/index.html",
      filename: "index.html",
    })
  ]
}
