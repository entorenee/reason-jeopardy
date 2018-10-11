const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

const mode = process.env.NODE_ENV === 'production' ? 'production' : 'development';

module.exports = {
  mode,
  entry: path.resolve(__dirname, './lib/js/src/Index.bs.js'),
  output: {
    path: path.resolve(__dirname, 'dist/'),
    filename: 'bundle.js',
  },
  plugins: [new HtmlWebpackPlugin({
    template: path.resolve(__dirname, 'src/index.html')
  })]
};
