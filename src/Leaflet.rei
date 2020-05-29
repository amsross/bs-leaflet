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

module TileLayer: {
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
};

module LatLngBounds: {
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
};

module LatLng: {
  let make: (float, float) => latLng;
  let equals: (latLng, latLng) => bool;
  let toString: latLng => string;
  let distanceTo: (latLng, latLng) => float;
  let wrap: latLng => latLng;
  let toBounds: (latLng, float) => latLngBounds;
};

module Map: {
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
};

module Bounds: {let make: (point, point) => bounds;};

module Point: {
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
};

module Popup: {
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
};
