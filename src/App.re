let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => <h1> {ReasonReact.string("Hello World")} </h1>,
};
