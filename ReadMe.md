# MiniTileRenderer

Work in progress for the worlds tiniest geospatial tile renderer.

## What?

Render GIS tiles ready for the web or elsewhere. Read vector data from Spatialite based on simple `.toml` configuration files. 

## Why?

For fun, and learning!

Aims to do one thing and one thing well (draw tiles), a la Mapserver. Forget logins, cors and caching. Those are better done by other services or your main application server.

Furthermore, I thought it'd be interesting to see what would happen if we allow other people to call the C code for the rendering directly from other languages. C is callable from a bunch of different languages (e.g. Python, C#) so it might be interesting to see how other people use it. I intend to write some examples of this myself to demonstrate what's possible. 

For example, what if your data is completely static and unchanging, and you only want to render tiles within a small space; e.g. a single county of a country? The best option could be to generate WMTS tiles as .png files and store them in a structured folder hierarchy based on X Y and Z of the WMTS requests. Then its a simple case of serving out static files from disk/ cache/ CDN.

To generate tiles in this example, your best bet is probably to use Mapnik, which can be used in either "server" mode with some setup, or as a command line tool. Someone, somewhere on the internet might have done this, so you can probably find some bash/ Python script that you could copy paste... But setting up and figuring it all out would take weeks or months.

With MiniTileRenderer, we don't aim to provide this functionality out of the box, but we aim to make it easy to do so using your own scripts that you can tailor exactly to your needs.


## Limitations 

- No support for coordinate systems other than web mercator. 
- No support for other vector data sources other than spatialite. POSTGIS support would be the best and easiest addition.
- Only supports simple geometries (points, lines, polygons).
- Probably full of memory leaks and security issues.
