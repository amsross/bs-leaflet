type tileLayer
and point = {
  x: float,
  y: float,
}
and latLng = {
  lat: float,
  lng: float,
  alt: option(float),
}
and latLngBounds = (latLng, latLng)
and map
and bounds = {
  min: point,
  max: point,
}
and popup;

module rec TileLayer: {
  type options;

  let options:
    (
      ~tileSize: int=?,
      ~opacity: float=?,
      ~updateWhenIdle: bool=?,
      ~updateWhenZooming: bool=?,
      ~updateInterval: int=?,
      ~zIndex: int=?,
      ~bounds: latLngBounds=?,
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

  let make: (string, options) => tileLayer;
  let addTo: (tileLayer, map) => tileLayer;
  let remove: tileLayer => tileLayer;
  let removeFrom: (tileLayer, map) => tileLayer;
} = {
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
      ~bounds: latLngBounds=?,
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

  [@bs.module "leaflet"]
  external make: (string, options) => tileLayer = "tileLayer";

  [@bs.send] external addTo: (tileLayer, map) => tileLayer = "addTo";
  [@bs.send] external removeFrom: (tileLayer, map) => tileLayer = "removeFrom";
  [@bs.send] external remove: tileLayer => tileLayer = "remove";
}

and LatLngBounds: {
  let make: (latLng, latLng) => latLngBounds;
  let extend: latLng => latLngBounds;
  let equals: latLngBounds => bool;
  let toBBoxString: latLngBounds => string;

  let getCenter: latLngBounds => latLng;
  let getSouthWest: latLngBounds => latLng;
  let getNorthEast: latLngBounds => latLng;
  let getNorthWest: latLngBounds => latLng;
  let getSouthEast: latLngBounds => latLng;
  let getWest: latLngBounds => latLng;
  let getSouth: latLngBounds => latLng;
  let getEast: latLngBounds => latLng;
  let getNorth: latLngBounds => latLng;
} = {
  [@bs.module "leaflet"]
  external make: (latLng, latLng) => latLngBounds = "latLngBounds";

  [@bs.send] external extend: latLng => latLngBounds = "extend";
  [@bs.send] external equals: latLngBounds => bool = "equals";
  [@bs.send] external toBBoxString: latLngBounds => string = "toBBoxString";

  [@bs.send] external getCenter: latLngBounds => latLng = "getCenter";
  [@bs.send] external getSouthWest: latLngBounds => latLng = "getSouthWest";
  [@bs.send] external getNorthEast: latLngBounds => latLng = "getNorthEast";
  [@bs.send] external getNorthWest: latLngBounds => latLng = "getNorthWest";
  [@bs.send] external getSouthEast: latLngBounds => latLng = "getSouthEast";
  [@bs.send] external getWest: latLngBounds => latLng = "getWest";
  [@bs.send] external getSouth: latLngBounds => latLng = "getSouth";
  [@bs.send] external getEast: latLngBounds => latLng = "getEast";
  [@bs.send] external getNorth: latLngBounds => latLng = "getNorth";
}

and LatLng: {
  let make: (float, float) => latLng;
  let equals: (latLng, latLng) => bool;
  let toString: latLng => string;
  let distanceTo: (latLng, latLng) => float;
  let wrap: latLng => latLng;
  let toBounds: (latLng, float) => latLngBounds;
} = {
  [@bs.module "leaflet"] external make: (float, float) => latLng = "latLng";

  [@bs.send] external equals: (latLng, latLng) => bool = "equals";
  [@bs.send] external toString: latLng => string = "toString";
  [@bs.send] external distanceTo: (latLng, latLng) => float = "distanceTo";
  [@bs.send] external wrap: latLng => latLng = "wrap";
  [@bs.send] external toBounds: (latLng, float) => latLngBounds = "toBounds";
}

and Map: {
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
      /* ~crs: cRS=?, */
      ~center: latLng=?,
      ~zoom: int=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      /* ~layers: array(layer)=?, */
      ~maxBounds: latLngBounds=?,
      /* ~renderer: renderer=?, */
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

  let make: (Dom.element, ~options: options=?, unit) => map;

  let setView: (map, latLng, int) => map;
  let flyTo: (map, latLng, ~zoom: int=?, unit) => map;
  let flyToBounds: (map, latLngBounds) => map;
  let stop: map => map;

  let getCenter: map => latLng;
  let getZoom: map => int;
  let getBounds: map => latLngBounds;
  let getMinZoom: map => int;
  let getMaxZoom: map => int;
  let getBoundsZoom:
    (map, latLngBounds, ~inside: bool=?, ~padding: point=?, unit) => int;
  let getSize: map => point;
  let getPixelBounds: map => bounds;
  let getPixelOrigin: map => point;
  let getPixelWorldBounds: (map, ~zoom: int=?, unit) => bounds;
} = {
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
      /* ~crs: cRS=?, */
      ~center: latLng=?,
      ~zoom: int=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      /* ~layers: array(layer)=?, */
      ~maxBounds: latLngBounds=?,
      /* ~renderer: renderer=?, */
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
  external make: (Dom.element, ~options: options=?, unit) => map = "map";

  [@bs.send] external setView: (map, latLng, int) => map = "setView";
  [@bs.send]
  external flyTo: (map, latLng, ~zoom: int=?, unit) => map = "flyTo";
  [@bs.send] external flyToBounds: (map, latLngBounds) => map = "flyToBounds";
  [@bs.send] external stop: map => map = "stop";

  [@bs.send] external getCenter: map => latLng = "getCenter";
  [@bs.send] external getZoom: map => int = "getZoom";
  [@bs.send] external getBounds: map => latLngBounds = "getBounds";
  [@bs.send] external getMinZoom: map => int = "getMinZoom";
  [@bs.send] external getMaxZoom: map => int = "getMaxZoom";
  [@bs.send]
  external getBoundsZoom:
    (map, latLngBounds, ~inside: bool=?, ~padding: point=?, unit) => int =
    "getBoundsZoom";
  [@bs.send] external getSize: map => point = "getSize";
  [@bs.send] external getPixelBounds: map => bounds = "getPixelBounds";
  [@bs.send] external getPixelOrigin: map => point = "getPixelOrigin";
  [@bs.send]
  external getPixelWorldBounds: (map, ~zoom: int=?, unit) => bounds =
    "getPixelWorldBounds";
}

and Bounds: {let make: (point, point) => bounds;} = {
  [@bs.module "leaflet"] external make: (point, point) => bounds = "bounds";
}

and Point: {
  let make: (float, float) => point;
  let add: (point, point) => point;
  let subtract: (point, point) => point;
  let divideBy: (point, float) => point;
  let multiplyBy: (point, float) => point;
  let scaleBy: (point, point) => point;
  let unscaleBy: (point, point) => point;
  let round: point => point;
  let floor: point => point;
  let ceil: point => point;
  let trunc: point => point;
  let distanceTo: (point, point) => point;
  let equals: (point, point) => point;
  let contains: (point, point) => point;
  let toString: point => string;
} = {
  [@bs.module "leaflet"] external make: (float, float) => point = "point";

  [@bs.send] external add: (point, point) => point = "add";
  [@bs.send] external subtract: (point, point) => point = "subtract";
  [@bs.send] external divideBy: (point, float) => point = "divideBy";
  [@bs.send] external multiplyBy: (point, float) => point = "multiplyBy";
  [@bs.send] external scaleBy: (point, point) => point = "scaleBy";
  [@bs.send] external unscaleBy: (point, point) => point = "unscaleBy";
  [@bs.send] external round: point => point = "round";
  [@bs.send] external floor: point => point = "floor";
  [@bs.send] external ceil: point => point = "ceil";
  [@bs.send] external trunc: point => point = "trunc";
  [@bs.send] external distanceTo: (point, point) => point = "distanceTo";
  [@bs.send] external equals: (point, point) => point = "equals";
  [@bs.send] external contains: (point, point) => point = "contains";
  [@bs.send] external toString: point => string = "toString";
}

and Popup: {
  type options;

  let options:
    (
      ~maxWidth: int=?,
      ~minWidth: int=?,
      ~maxHeight: int=?,
      ~autoPan: bool=?,
      ~autoPanPaddingTopLeft: point=?,
      ~autoPanPaddingBottomRight: point=?,
      ~autoPanPadding: point=?,
      ~keepInView: bool=?,
      ~closeButton: bool=?,
      ~autoClose: bool=?,
      ~closeOnEscapeKey: bool=?,
      ~closeOnClick: bool=?,
      ~className: string=?,
      ~offset: point=?,
      ~pane: string=?,
      ~attribution: string=?,
      unit
    ) =>
    options;

  let make: (~options: options=?, unit) => popup;

  let getLatLng: popup => latLng;
  let setLatLng: (popup, latLng) => popup;
  let getContent: popup => Dom.element;
  let setContent: (popup, Dom.element) => popup;
  let getElement: popup => Dom.element;
  let update: popup => unit;
  let bringToFront: popup => popup;
  let bringToBack: popup => popup;
  let isOpen: popup => bool;
  let openOn: (popup, map) => popup;
} = {
  type options;

  [@bs.obj]
  external options:
    (
      ~maxWidth: int=?,
      ~minWidth: int=?,
      ~maxHeight: int=?,
      ~autoPan: bool=?,
      ~autoPanPaddingTopLeft: point=?,
      ~autoPanPaddingBottomRight: point=?,
      ~autoPanPadding: point=?,
      ~keepInView: bool=?,
      ~closeButton: bool=?,
      ~autoClose: bool=?,
      ~closeOnEscapeKey: bool=?,
      ~closeOnClick: bool=?,
      ~className: string=?,
      ~offset: point=?,
      ~pane: string=?,
      ~attribution: string=?,
      unit
    ) =>
    options;

  [@bs.module "leaflet"]
  external make: (~options: options=?, unit) => popup = "popup";

  [@bs.send] external getLatLng: popup => latLng = "getLatLng";
  [@bs.send] external setLatLng: (popup, latLng) => popup = "setLatLng";
  [@bs.send] external getContent: popup => Dom.element = "getContent";
  [@bs.send] external setContent: (popup, Dom.element) => popup = "setContent";
  [@bs.send] external getElement: popup => Dom.element = "getElement";
  [@bs.send] external update: popup => unit = "update";
  [@bs.send] external bringToFront: popup => popup = "bringToFront";
  [@bs.send] external bringToBack: popup => popup = "bringToBack";
  [@bs.send] external isOpen: popup => bool = "isOpen";
  [@bs.send] external openOn: (popup, map) => popup = "openOn";
};
