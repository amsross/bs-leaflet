type tileLayer
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

type event_('t, 'a) =
  {
    ..
    _type: string,
    target: 't,
  } as 'a

and base_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
      },
    ),
  )

and keyboard_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        originalEvent: Dom.event,
      },
    ),
  )

and mouse_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        latlng: latLng,
        layerPoint: point,
        containerPoint: point,
        originalEvent: Dom.event,
      },
    ),
  )

and location_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        latlng: latLng,
        bounds: latLngBounds,
        accuracy: float,
        altitude: float,
        altitudeAccuracy: float,
        heading: float,
        speed: float,
        timestamp: float,
      },
    ),
  )

and error_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        message: string,
        code: int,
      },
    ),
  )

and layer_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        layer: layer,
      },
    ),
  )

and layers_control_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        layer: layer,
        name: layer,
      },
    ),
  )

and tile_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        tile: Dom.htmlElement,
        coords: point,
      },
    ),
  )

and tile_error_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        coords: point,
        error: Js.t({.}),
      },
    ),
  )

and resize_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        oldSize: point,
        newSize: point,
      },
    ),
  )

and geo_json_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        layer: layer,
        properties: Js.t({.}),
        geometryType: string,
        id: string,
      },
    ),
  )

and popup_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        popup: popup,
      },
    ),
  )

and tooltip_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        tooltip: tooltip,
      },
    ),
  )

and drag_end_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        distance: float,
      },
    ),
  )

and zoom_anim_event('t) =
  Js.t(
    event_(
      't,
      {
        .
        _type: string,
        target: 't,
        center: latLng,
        zoom: int,
        noUpdate: bool,
      },
    ),
  );

module TileLayer = {
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
};

module LatLngBounds = {
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
};

module LatLng = {
  [@bs.module "leaflet"] external make: (float, float) => latLng = "latLng";

  [@bs.send] external equals: (latLng, latLng) => bool = "equals";
  [@bs.send] external toString: latLng => string = "toString";
  [@bs.send] external distanceTo: (latLng, latLng) => float = "distanceTo";
  [@bs.send] external wrap: latLng => latLng = "wrap";
  [@bs.send] external toBounds: (latLng, float) => latLngBounds = "toBounds";
};

module Map = {
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

  [@bs.send]
  external on:
    (
      map,
      [@bs.string] [
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
    map =
    "on";

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
};

module Bounds = {
  [@bs.module "leaflet"] external make: (point, point) => bounds = "bounds";
};

module Point = {
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
};

module Popup = {
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
