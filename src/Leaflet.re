module rec TileLayer: {
  type t;
  type options;

  let options:
    (
      ~tileSize: int=?,
      ~opacity: float=?,
      ~updateWhenIdle: bool=?,
      ~updateWhenZooming: bool=?,
      ~updateInterval: int=?,
      ~zIndex: int=?,
      ~bounds: LatLngBounds.t=?,
      ~maxNativeZoom: int=?,
      ~minNativeZoom: int=?,
      ~noWrap: bool=?,
      ~pane: string=?,
      ~className: string=?,
      ~keepBuffer: int=?,
      ~attribution: string=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      ~subdomains: array(string)=?,
      ~errorTileUrl: string=?,
      ~zoomOffset: int=?,
      ~tms: bool=?,
      ~zoomReverse: bool=?,
      ~detectRetina: bool=?,
      ~crossOrigin: string=?,
      ~id: string=?,
      ~accessToken: string=?,
      unit
    ) =>
    options;

  let make: (string, options) => t;
  let addTo: (t, Map.t) => t;
  let remove: t => t;
  let removeFrom: (t, Map.t) => t;
} = {
  type t;
  type options;

  [@bs.obj]
  external options:
    (
      ~tileSize: int=?,
      ~opacity: float=?,
      ~updateWhenIdle: bool=?,
      ~updateWhenZooming: bool=?,
      ~updateInterval: int=?,
      ~zIndex: int=?,
      ~bounds: LatLngBounds.t=?,
      ~maxNativeZoom: int=?,
      ~minNativeZoom: int=?,
      ~noWrap: bool=?,
      ~pane: string=?,
      ~className: string=?,
      ~keepBuffer: int=?,
      ~attribution: string=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      ~subdomains: array(string)=?,
      ~errorTileUrl: string=?,
      ~zoomOffset: int=?,
      ~tms: bool=?,
      ~zoomReverse: bool=?,
      ~detectRetina: bool=?,
      ~crossOrigin: string=?,
      ~id: string=?,
      ~accessToken: string=?,
      unit
    ) =>
    options;

  [@bs.module "leaflet"] external make: (string, options) => t = "tileLayer";

  [@bs.send] external addTo: (t, Map.t) => t = "addTo";
  [@bs.send] external removeFrom: (t, Map.t) => t = "removeFrom";
  [@bs.send] external remove: t => t = "remove";
}

and LatLngBounds: {
  type t;

  let make: (LatLng.t, LatLng.t) => t;
  let extend: LatLng.t => t;
  let equals: t => bool;
  let toBBoxString: t => string;

  let getCenter: t => LatLng.t;
  let getSouthWest: t => LatLng.t;
  let getNorthEast: t => LatLng.t;
  let getNorthWest: t => LatLng.t;
  let getSouthEast: t => LatLng.t;
  let getWest: t => LatLng.t;
  let getSouth: t => LatLng.t;
  let getEast: t => LatLng.t;
  let getNorth: t => LatLng.t;
} = {
  type t = (LatLng.t, LatLng.t);

  [@bs.module "leaflet"]
  external make: (LatLng.t, LatLng.t) => t = "latLngBounds";

  [@bs.send] external extend: LatLng.t => t = "extend";
  [@bs.send] external equals: t => bool = "equals";
  [@bs.send] external toBBoxString: t => string = "toBBoxString";

  [@bs.send] external getCenter: t => LatLng.t = "getCenter";
  [@bs.send] external getSouthWest: t => LatLng.t = "getSouthWest";
  [@bs.send] external getNorthEast: t => LatLng.t = "getNorthEast";
  [@bs.send] external getNorthWest: t => LatLng.t = "getNorthWest";
  [@bs.send] external getSouthEast: t => LatLng.t = "getSouthEast";
  [@bs.send] external getWest: t => LatLng.t = "getWest";
  [@bs.send] external getSouth: t => LatLng.t = "getSouth";
  [@bs.send] external getEast: t => LatLng.t = "getEast";
  [@bs.send] external getNorth: t => LatLng.t = "getNorth";
}

and LatLng: {
  type t = {
    lat: float,
    lng: float,
    alt: option(float),
  };

  let make: (float, float) => t;
  let equals: (t, t) => bool;
  let toString: t => string;
  let distanceTo: (t, t) => float;
  let wrap: t => t;
  let toBounds: (t, float) => LatLngBounds.t;
} = {
  type t = {
    lat: float,
    lng: float,
    alt: option(float),
  };

  [@bs.module "leaflet"] external make: (float, float) => t = "latLng";

  [@bs.send] external equals: (t, t) => bool = "equals";
  [@bs.send] external toString: t => string = "toString";
  [@bs.send] external distanceTo: (t, t) => float = "distanceTo";
  [@bs.send] external wrap: t => t = "wrap";
  [@bs.send] external toBounds: (t, float) => LatLngBounds.t = "toBounds";
}

and Map: {
  type t;
  type options;

  let options:
    (
      ~preferCanvas: bool=?,
      ~attributionControl: bool=?,
      ~zoomControl: bool=?,
      ~closePopupOnClick: bool=?,
      ~zoomSnap: int=?,
      ~zoomDelta: int=?,
      ~trackResize: bool=?,
      ~boxZoom: bool=?,
      ~doubleClickZoom: bool=?,
      ~dragging: bool=?,
      /* ~crs: CRS.t=?, */
      ~center: LatLng.t=?,
      ~zoom: int=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      /* ~layers: array(Layer.t)=?, */
      ~maxBounds: LatLngBounds.t=?,
      /* ~renderer: Renderer.t=?, */
      ~inertia: bool=?,
      ~inertiaDeceleration: float=?,
      ~inertiaMaxSpeed: float=?,
      ~easeLinearity: float=?,
      ~worldCopyJump: bool=?,
      ~maxBoundsViscosity: int=?,
      ~keyboard: bool=?,
      ~keyboardPanDelta: int=?,
      ~scrollWheelZoom: bool=?,
      ~wheelDebounceTime: int=?,
      ~wheelPxPerZoomLevel: int=?,
      ~tap: bool=?,
      ~tapTolerance: int=?,
      ~touchZoom: bool=?,
      ~bounceAtZoomLimits: bool=?,
      unit
    ) =>
    options;

  module Event: {
    type t = {
      [@bs.as "type"]
      type_: string,
      target: Map.t,
    };
  };

  let make: (Dom.element, ~options: options=?, unit) => t;

  let on: (t, [ | `move(Event.t => unit)]) => t;

  let setView: (t, LatLng.t, int) => t;
  let flyTo: (t, LatLng.t, ~zoom: int=?, unit) => t;
  let flyToBounds: (t, LatLngBounds.t) => t;
  let stop: t => t;

  let getCenter: t => LatLng.t;
  let getZoom: t => int;
  let getBounds: t => LatLngBounds.t;
  let getMinZoom: t => int;
  let getMaxZoom: t => int;
  let getBoundsZoom:
    (t, LatLngBounds.t, ~inside: bool=?, ~padding: Point.t=?, unit) => int;
  let getSize: t => Point.t;
  let getPixelBounds: t => Bounds.t;
  let getPixelOrigin: t => Point.t;
  let getPixelWorldBounds: (t, ~zoom: int=?, unit) => Bounds.t;
} = {
  type t;
  type options;

  [@bs.obj]
  external options:
    (
      ~preferCanvas: bool=?,
      ~attributionControl: bool=?,
      ~zoomControl: bool=?,
      ~closePopupOnClick: bool=?,
      ~zoomSnap: int=?,
      ~zoomDelta: int=?,
      ~trackResize: bool=?,
      ~boxZoom: bool=?,
      ~doubleClickZoom: bool=?,
      ~dragging: bool=?,
      /* ~crs: CRS.t=?, */
      ~center: LatLng.t=?,
      ~zoom: int=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      /* ~layers: array(Layer.t)=?, */
      ~maxBounds: LatLngBounds.t=?,
      /* ~renderer: Renderer.t=?, */
      ~inertia: bool=?,
      ~inertiaDeceleration: float=?,
      ~inertiaMaxSpeed: float=?,
      ~easeLinearity: float=?,
      ~worldCopyJump: bool=?,
      ~maxBoundsViscosity: int=?,
      ~keyboard: bool=?,
      ~keyboardPanDelta: int=?,
      ~scrollWheelZoom: bool=?,
      ~wheelDebounceTime: int=?,
      ~wheelPxPerZoomLevel: int=?,
      ~tap: bool=?,
      ~tapTolerance: int=?,
      ~touchZoom: bool=?,
      ~bounceAtZoomLimits: bool=?,
      unit
    ) =>
    options;

  [@bs.module "leaflet"]
  external make: (Dom.element, ~options: options=?, unit) => t = "map";

  module Event = {
    type t = {
      [@bs.as "type"]
      type_: string,
      target: Map.t,
    };
  };

  [@bs.send]
  external on: (t, [@bs.string] [ | `move(Event.t => unit)]) => t = "on";

  [@bs.send] external setView: (t, LatLng.t, int) => t = "setView";
  [@bs.send] external flyTo: (t, LatLng.t, ~zoom: int=?, unit) => t = "flyTo";
  [@bs.send] external flyToBounds: (t, LatLngBounds.t) => t = "flyToBounds";
  [@bs.send] external stop: t => t = "stop";

  [@bs.send] external getCenter: t => LatLng.t = "getCenter";
  [@bs.send] external getZoom: t => int = "getZoom";
  [@bs.send] external getBounds: t => LatLngBounds.t = "getBounds";
  [@bs.send] external getMinZoom: t => int = "getMinZoom";
  [@bs.send] external getMaxZoom: t => int = "getMaxZoom";
  [@bs.send]
  external getBoundsZoom:
    (t, LatLngBounds.t, ~inside: bool=?, ~padding: Point.t=?, unit) => int =
    "getBoundsZoom";
  [@bs.send] external getSize: t => Point.t = "getSize";
  [@bs.send] external getPixelBounds: t => Bounds.t = "getPixelBounds";
  [@bs.send] external getPixelOrigin: t => Point.t = "getPixelOrigin";
  [@bs.send]
  external getPixelWorldBounds: (t, ~zoom: int=?, unit) => Bounds.t =
    "getPixelWorldBounds";
}

and Bounds: {
  type t = {
    min: Point.t,
    max: Point.t,
  };

  let make: (Point.t, Point.t) => t;
} = {
  type t = {
    min: Point.t,
    max: Point.t,
  };

  [@bs.module "leaflet"] external make: (Point.t, Point.t) => t = "bounds";
}

and Point: {
  type t = {
    x: float,
    y: float,
  };

  let make: (float, float) => t;
  let add: (t, t) => t;
  let subtract: (t, t) => t;
  let divideBy: (t, float) => t;
  let multiplyBy: (t, float) => t;
  let scaleBy: (t, Point.t) => t;
  let unscaleBy: (t, Point.t) => t;
  let round: t => t;
  let floor: t => t;
  let ceil: t => t;
  let trunc: t => t;
  let distanceTo: (t, Point.t) => t;
  let equals: (t, Point.t) => t;
  let contains: (t, Point.t) => t;
  let toString: t => string;
} = {
  type t = {
    x: float,
    y: float,
  };

  [@bs.module "leaflet"] external make: (float, float) => t = "point";

  [@bs.send] external add: (t, t) => t = "add";
  [@bs.send] external subtract: (t, t) => t = "subtract";
  [@bs.send] external divideBy: (t, float) => t = "divideBy";
  [@bs.send] external multiplyBy: (t, float) => t = "multiplyBy";
  [@bs.send] external scaleBy: (t, Point.t) => t = "scaleBy";
  [@bs.send] external unscaleBy: (t, Point.t) => t = "unscaleBy";
  [@bs.send] external round: t => t = "round";
  [@bs.send] external floor: t => t = "floor";
  [@bs.send] external ceil: t => t = "ceil";
  [@bs.send] external trunc: t => t = "trunc";
  [@bs.send] external distanceTo: (t, Point.t) => t = "distanceTo";
  [@bs.send] external equals: (t, Point.t) => t = "equals";
  [@bs.send] external contains: (t, Point.t) => t = "contains";
  [@bs.send] external toString: t => string = "toString";
}

and Popup: {
  type t;
  type options;

  let options:
    (
      ~maxWidth: int=?,
      ~minWidth: int=?,
      ~maxHeight: int=?,
      ~autoPan: bool=?,
      ~autoPanPaddingTopLeft: Point.t=?,
      ~autoPanPaddingBottomRight: Point.t=?,
      ~autoPanPadding: Point.t=?,
      ~keepInView: bool=?,
      ~closeButton: bool=?,
      ~autoClose: bool=?,
      ~closeOnEscapeKey: bool=?,
      ~closeOnClick: bool=?,
      ~className: string=?,
      ~offset: Point.t=?,
      ~pane: string=?,
      ~attribution: string=?,
      unit
    ) =>
    options;

  let make: (~options: options=?, unit) => t;

  let getLatLng: t => LatLng.t;
  let setLatLng: (t, LatLng.t) => t;
  let getContent: t => Dom.element;
  let setContent: (t, Dom.element) => t;
  let getElement: t => Dom.element;
  let update: t => unit;
  let bringToFront: t => t;
  let bringToBack: t => t;
  let isOpen: t => bool;
  let openOn: (t, Map.t) => t;
} = {
  type t;
  type options;

  [@bs.obj]
  external options:
    (
      ~maxWidth: int=?,
      ~minWidth: int=?,
      ~maxHeight: int=?,
      ~autoPan: bool=?,
      ~autoPanPaddingTopLeft: Point.t=?,
      ~autoPanPaddingBottomRight: Point.t=?,
      ~autoPanPadding: Point.t=?,
      ~keepInView: bool=?,
      ~closeButton: bool=?,
      ~autoClose: bool=?,
      ~closeOnEscapeKey: bool=?,
      ~closeOnClick: bool=?,
      ~className: string=?,
      ~offset: Point.t=?,
      ~pane: string=?,
      ~attribution: string=?,
      unit
    ) =>
    options;

  [@bs.module "leaflet"]
  external make: (~options: options=?, unit) => t = "popup";

  [@bs.send] external getLatLng: t => LatLng.t = "getLatLng";
  [@bs.send] external setLatLng: (t, LatLng.t) => t = "setLatLng";
  [@bs.send] external getContent: t => Dom.element = "getContent";
  [@bs.send] external setContent: (t, Dom.element) => t = "setContent";
  [@bs.send] external getElement: t => Dom.element = "getElement";
  [@bs.send] external update: t => unit = "update";
  [@bs.send] external bringToFront: t => t = "bringToFront";
  [@bs.send] external bringToBack: t => t = "bringToBack";
  [@bs.send] external isOpen: t => bool = "isOpen";
  [@bs.send] external openOn: (t, Map.t) => t = "openOn";
};
