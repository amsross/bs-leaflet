type rec tileLayer
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
  alt: option<float>,
}
and latLngBounds = (latLng, latLng)
and map
and bounds = {
  min: point,
  max: point,
}
and popup

type rec event_<'t, 'a> = {.."_type": string, "target": 't} as 'a

and base_event<'t> = Js.t<event_<'t, {"_type": string, "target": 't}>>

and keyboard_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "originalEvent": Dom.event}>,
>

and mouse_event<'t> = Js.t<
  event_<
    't,
    {
      "_type": string,
      "target": 't,
      "latlng": latLng,
      "layerPoint": point,
      "containerPoint": point,
      "originalEvent": Dom.event,
    },
  >,
>

and location_event<'t> = Js.t<
  event_<
    't,
    {
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
    },
  >,
>

and error_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "message": string, "code": int}>,
>

and layer_event<'t> = Js.t<event_<'t, {"_type": string, "target": 't, "layer": layer}>>

and layers_control_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "layer": layer, "name": layer}>,
>

and tile_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "tile": Dom.htmlElement, "coords": point}>,
>

and tile_error_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "coords": point, "error": {.}}>,
>

and resize_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "oldSize": point, "newSize": point}>,
>

and geo_json_event<'t> = Js.t<
  event_<
    't,
    {
      "_type": string,
      "target": 't,
      "layer": layer,
      "properties": {.},
      "geometryType": string,
      "id": string,
    },
  >,
>

and popup_event<'t> = Js.t<event_<'t, {"_type": string, "target": 't, "popup": popup}>>

and tooltip_event<'t> = Js.t<event_<'t, {"_type": string, "target": 't, "tooltip": tooltip}>>

and drag_end_event<'t> = Js.t<event_<'t, {"_type": string, "target": 't, "distance": float}>>

and zoom_anim_event<'t> = Js.t<
  event_<'t, {"_type": string, "target": 't, "center": latLng, "zoom": int, "noUpdate": bool}>,
>

module TileLayer = {
  type options

  @obj
  external options: (
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
    ~subdomains: array<string>=?,
    ~errorTileUrl: string=?,
    ~zoomOffset: int=?,
    ~tms: bool=?,
    ~zoomReverse: bool=?,
    ~detectRetina: bool=?,
    ~crossOrigin: string=?,
    ~id: string=?,
    ~accessToken: string=?,
    unit,
  ) => options = ""

  @module("leaflet")
  external make: (string, options) => tileLayer = "tileLayer"

  @send external addTo: (tileLayer, map) => tileLayer = "addTo"
  @send external removeFrom: (tileLayer, map) => tileLayer = "removeFrom"
  @send external remove: tileLayer => tileLayer = "remove"
}

module LatLngBounds = {
  @module("leaflet")
  external make: (latLng, latLng) => latLngBounds = "latLngBounds"

  @send external extend: latLng => latLngBounds = "extend"
  @send external equals: latLngBounds => bool = "equals"
  @send external toBBoxString: latLngBounds => string = "toBBoxString"

  @send external getCenter: latLngBounds => latLng = "getCenter"
  @send external getSouthWest: latLngBounds => latLng = "getSouthWest"
  @send external getNorthEast: latLngBounds => latLng = "getNorthEast"
  @send external getNorthWest: latLngBounds => latLng = "getNorthWest"
  @send external getSouthEast: latLngBounds => latLng = "getSouthEast"
  @send external getWest: latLngBounds => latLng = "getWest"
  @send external getSouth: latLngBounds => latLng = "getSouth"
  @send external getEast: latLngBounds => latLng = "getEast"
  @send external getNorth: latLngBounds => latLng = "getNorth"
}

module LatLng = {
  @module("leaflet") external make: (float, float) => latLng = "latLng"

  @send external equals: (latLng, latLng) => bool = "equals"
  @send external toString: latLng => string = "toString"
  @send external distanceTo: (latLng, latLng) => float = "distanceTo"
  @send external wrap: latLng => latLng = "wrap"
  @send external toBounds: (latLng, float) => latLngBounds = "toBounds"
}

module Map = {
  type options

  @obj
  external options: (
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
    ~layers: array<layer>=?,
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
    unit,
  ) => options = ""

  @module("leaflet")
  external make: (Dom.element, ~options: options=?, unit) => map = "map"

  @send
  external on: (
    map,
    @string
    [
      | #baselayerchange(layers_control_event<map> => unit)
      | #overlayadd(layers_control_event<map> => unit)
      | #overlayremove(layers_control_event<map> => unit)
      | #layeradd(layer_event<map> => unit)
      | #layerremove(layer_event<map> => unit)
      | #zoomlevelschange(base_event<map> => unit)
      | #resize(resize_event<map> => unit)
      | #unload(base_event<map> => unit)
      | #viewreset(base_event<map> => unit)
      | #load(base_event<map> => unit)
      | #zoomstart(base_event<map> => unit)
      | #movestart(base_event<map> => unit)
      | #zoom(base_event<map> => unit)
      | #move(base_event<map> => unit)
      | #zoomend(base_event<map> => unit)
      | #moveend(base_event<map> => unit)
      | #popupopen(popup_event<map> => unit)
      | #popupclose(popup_event<map> => unit)
      | #autopanstart(base_event<map> => unit)
      | #tooltipopen(tooltip_event<map> => unit)
      | #tooltipclose(tooltip_event<map> => unit)
      | #locationerror(error_event<map> => unit)
      | #locationfound(location_event<map> => unit)
      | #click(mouse_event<map> => unit)
      | #dblclick(mouse_event<map> => unit)
      | #mousedown(mouse_event<map> => unit)
      | #mouseup(mouse_event<map> => unit)
      | #mouseover(mouse_event<map> => unit)
      | #mouseout(mouse_event<map> => unit)
      | #mousemove(mouse_event<map> => unit)
      | #contextmenu(mouse_event<map> => unit)
      | #keypress(keyboard_event<map> => unit)
      | #keydown(keyboard_event<map> => unit)
      | #keyup(keyboard_event<map> => unit)
      | #preclick(mouse_event<map> => unit)
      | #zoomanim(zoom_anim_event<map> => unit)
    ],
  ) => map = "on"

  @send
  external off: (
    map,
    @string
    [
      | #baselayerchange(layers_control_event<map> => unit)
      | #overlayadd(layers_control_event<map> => unit)
      | #overlayremove(layers_control_event<map> => unit)
      | #layeradd(layer_event<map> => unit)
      | #layerremove(layer_event<map> => unit)
      | #zoomlevelschange(base_event<map> => unit)
      | #resize(resize_event<map> => unit)
      | #unload(base_event<map> => unit)
      | #viewreset(base_event<map> => unit)
      | #load(base_event<map> => unit)
      | #zoomstart(base_event<map> => unit)
      | #movestart(base_event<map> => unit)
      | #zoom(base_event<map> => unit)
      | #move(base_event<map> => unit)
      | #zoomend(base_event<map> => unit)
      | #moveend(base_event<map> => unit)
      | #popupopen(popup_event<map> => unit)
      | #popupclose(popup_event<map> => unit)
      | #autopanstart(base_event<map> => unit)
      | #tooltipopen(tooltip_event<map> => unit)
      | #tooltipclose(tooltip_event<map> => unit)
      | #locationerror(error_event<map> => unit)
      | #locationfound(location_event<map> => unit)
      | #click(mouse_event<map> => unit)
      | #dblclick(mouse_event<map> => unit)
      | #mousedown(mouse_event<map> => unit)
      | #mouseup(mouse_event<map> => unit)
      | #mouseover(mouse_event<map> => unit)
      | #mouseout(mouse_event<map> => unit)
      | #mousemove(mouse_event<map> => unit)
      | #contextmenu(mouse_event<map> => unit)
      | #keypress(keyboard_event<map> => unit)
      | #keydown(keyboard_event<map> => unit)
      | #keyup(keyboard_event<map> => unit)
      | #preclick(mouse_event<map> => unit)
      | #zoomanim(zoom_anim_event<map> => unit)
    ],
  ) => map = "off"

  @send external setView: (map, latLng, int) => map = "setView"
  @send
  external flyTo: (map, latLng, ~zoom: int=?, unit) => map = "flyTo"
  @send external flyToBounds: (map, latLngBounds) => map = "flyToBounds"
  @send external stop: map => map = "stop"
  @send external remove: map => map = "remove"
  @send external locate: map => map = "locate"

  @send external getCenter: map => latLng = "getCenter"
  @send external getZoom: map => int = "getZoom"
  @send external getBounds: map => latLngBounds = "getBounds"
  @send external getMinZoom: map => int = "getMinZoom"
  @send external getMaxZoom: map => int = "getMaxZoom"
  @send
  external getBoundsZoom: (map, latLngBounds, ~inside: bool=?, ~padding: point=?, unit) => int =
    "getBoundsZoom"
  @send external getSize: map => point = "getSize"
  @send external getPixelBounds: map => bounds = "getPixelBounds"
  @send external getPixelOrigin: map => point = "getPixelOrigin"
  @send
  external getPixelWorldBounds: (map, ~zoom: int=?, unit) => bounds = "getPixelWorldBounds"
}

module Bounds = {
  @module("leaflet") external make: (point, point) => bounds = "bounds"
}

module Point = {
  @module("leaflet") external make: (float, float) => point = "point"

  @send external add: (point, point) => point = "add"
  @send external subtract: (point, point) => point = "subtract"
  @send external divideBy: (point, float) => point = "divideBy"
  @send external multiplyBy: (point, float) => point = "multiplyBy"
  @send external scaleBy: (point, point) => point = "scaleBy"
  @send external unscaleBy: (point, point) => point = "unscaleBy"
  @send external round: point => point = "round"
  @send external floor: point => point = "floor"
  @send external ceil: point => point = "ceil"
  @send external trunc: point => point = "trunc"
  @send external distanceTo: (point, point) => point = "distanceTo"
  @send external equals: (point, point) => point = "equals"
  @send external contains: (point, point) => point = "contains"
  @send external toString: point => string = "toString"
}

module Popup = {
  type options

  @obj
  external options: (
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
    unit,
  ) => options = ""

  @module("leaflet")
  external make: (~options: options=?, unit) => popup = "popup"

  @send external getLatLng: popup => latLng = "getLatLng"
  @send external setLatLng: (popup, latLng) => popup = "setLatLng"
  @send external getContent: popup => Dom.element = "getContent"
  @send external setContent: (popup, Dom.element) => popup = "setContent"
  @send external getElement: popup => Dom.element = "getElement"
  @send external update: popup => unit = "update"
  @send external bringToFront: popup => popup = "bringToFront"
  @send external bringToBack: popup => popup = "bringToBack"
  @send external isOpen: popup => bool = "isOpen"
  @send external openOn: (popup, map) => popup = "openOn"
}
