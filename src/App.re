type category = {
  id: int,
  title: string,
  cluesCount: int,
};

type categories = array(category);

type action =
  | FetchCategories
  | CategoriesFetched(categories);

type categoriesState =
  | Loading
  | Loaded(categories);

type state = {categories: categoriesState};

module Decode = {
  let catData = json =>
    Json.Decode.{
      id: json |> field("id", int),
      title: json |> field("title", string),
      cluesCount: json |> field("clues_count", int),
    };

  let catArr = Json.Decode.array(catData);
};

let baseUrl = "http://jservice.io/api";

let randomCatGen = Random.int(10);

let fetchCategoriesSideEffects = self =>
  ReasonReact.(
    Js.Promise.(
      Fetch.fetch({j|$baseUrl/categories/?count=5&offset=5|j})
      |> then_(Fetch.Response.json)
      |> then_(json =>
           Decode.catArr(json)
           |> (
             categories =>
               self.send(CategoriesFetched(categories)) |> resolve
           )
         )
      |> ignore
    )
  );

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {categories: Loading},
  reducer: (action, _state) =>
    switch (action) {
    | FetchCategories => ReasonReact.SideEffects(fetchCategoriesSideEffects)
    | CategoriesFetched(categories) =>
      ReasonReact.Update({categories: Loaded(categories)})
    },
  didMount: self => self.send(FetchCategories),
  render: ({state: {categories}}) =>
    <div>
      <h1> {ReasonReact.string("Hello World")} </h1>
      {
        switch (categories) {
        | Loading => <p> {ReasonReact.string("Loading")} </p>
        | Loaded(cats) =>
          <ul>
            {
              ReasonReact.array(
                Array.map(
                  ({title}) =>
                    <li key=title> {ReasonReact.string(title)} </li>,
                  cats,
                ),
              )
            }
          </ul>
        }
      }
    </div>,
};
