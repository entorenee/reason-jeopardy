# Reason Jeopardy

## Run Project

```sh
yarn
yarn start
# in another tab
yarn dev
```

This will start the BuckleScript compiler and a Webpack Dev Server with hot reloading. Keep the BuckleScript compiler tab accessible (the one running `yarn start`) for helpful compiler errors.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Build for Production

```sh
yarn build
yarn webpack:build
```

This will replace the development artifact `dist/bundle.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
