type tileLayer
and renderer
and crs
and tooltip
and layer
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

type base_event('t) = {
  .
  "_type": string,
  "target": 't,
}

and keyboard_event('t) = {
  .
  "_type": string,
  "target": 't,
  "originalEvent": Dom.event,
}

and mouse_event('t) = {
  .
  "_type": string,
  "target": 't,
  "latlng": latLng,
  "layerPoint": point,
  "containerPoint": point,
  "originalEvent": Dom.event,
}

and location_event('t) = {
  .
  "_type": string,
  "target": 't,
  "latlng": latLng,
  "bounds": latLngBounds,
  "accuracy": float,
  "altitude": float,
  "altitudeAccuracy": float,
  "heading": float,
  "speed": float,
  "timestamp": float,
}

and error_event('t) = {
  .
  "_type": string,
  "target": 't,
  "message": string,
  "code": int,
}

and layer_event('t) = {
  .
  "_type": string,
  "target": 't,
  "layer": layer,
}

and layers_control_event('t) = {
  .
  "_type": string,
  "target": 't,
  "layer": layer,
  "name": layer,
}

and tile_event('t) = {
  .
  "_type": string,
  "target": 't,
  "tile": Dom.htmlElement,
  "coords": point,
}

and tile_error_event('t) = {
  .
  "_type": string,
  "target": 't,
  "coords": point,
  "error": Js.t({.}),
}

and resize_event('t) = {
  .
  "_type": string,
  "target": 't,
  "oldSize": point,
  "newSize": point,
}

and geo_json_event('t) = {
  .
  "_type": string,
  "target": 't,
  "layer": layer,
  "properties": Js.t({.}),
  "geometryType": string,
  "id": string,
}

and popup_event('t) = {
  .
  "_type": string,
  "target": 't,
  "popup": popup,
}

and tooltip_event('t) = {
  .
  "_type": string,
  "target": 't,
  "tooltip": tooltip,
}

and drag_end_event('t) = {
  .
  "_type": string,
  "target": 't,
  "distance": float,
}

and zoom_anim_event('t) = {
  .
  "_type": string,
  "target": 't,
  "center": latLng,
  "zoom": int,
  "noUpdate": bool,
};

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
      ~crs: crs=?,
      ~center: latLng=?,
      ~zoom: int=?,
      ~minZoom: int=?,
      ~maxZoom: int=?,
      ~layers: array(layer)=?,
      ~maxBounds: latLngBounds=?,
      ~renderer: renderer=?,
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

  let on:
    (
      map,
      [
        | `baselayerchange(layers_control_event(map) => unit)
        | `overlayadd(layers_control_event(map) => unit)
        | `overlayremove(layers_control_event(map) => unit)
        | `layeradd(layer_event(map) => unit)
        | `layerremove(layer_event(map) => unit)
        | `zoomlevelschange(base_event(map) => unit)
        | `resize(resize_event(map) => unit)
        | `unload(base_event(map) => unit)
        | `viewreset(base_event(map) => unit)
        | `load(base_event(map) => unit)
        | `zoomstart(base_event(map) => unit)
        | `movestart(base_event(map) => unit)
        | `zoom(base_event(map) => unit)
        | `move(base_event(map) => unit)
        | `zoomend(base_event(map) => unit)
        | `moveend(base_event(map) => unit)
        | `popupopen(popup_event(map) => unit)
        | `popupclose(popup_event(map) => unit)
        | `autopanstart(base_event(map) => unit)
        | `tooltipopen(tooltip_event(map) => unit)
        | `tooltipclose(tooltip_event(map) => unit)
        | `locationerror(error_event(map) => unit)
        | `locationfound(location_event(map) => unit)
        | `click(mouse_event(map) => unit)
        | `dblclick(mouse_event(map) => unit)
        | `mousedown(mouse_event(map) => unit)
        | `mouseup(mouse_event(map) => unit)
        | `mouseover(mouse_event(map) => unit)
        | `mouseout(mouse_event(map) => unit)
        | `mousemove(mouse_event(map) => unit)
        | `contextmenu(mouse_event(map) => unit)
        | `keypress(keyboard_event(map) => unit)
        | `keydown(keyboard_event(map) => unit)
        | `keyup(keyboard_event(map) => unit)
        | `preclick(mouse_event(map) => unit)
        | `zoomanim(zoom_anim_event(map) => unit)
      ]
    ) =>
    map;

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
