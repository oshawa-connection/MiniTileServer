# MiniTileRenderer

Work in progress for the worlds tiniest geospatial tile renderer.

## What?

Render map tiles ready for the web or elsewhere. Read vector data from spatialite database based on simple `.toml` configuration files. 

### What are tiles?

Serving geospatial data to web maps is often difficult as these datasets tend to be large. Therefore, tile servers draw a .png of a small section of the data, styling and text labels included. This improves the performance of web maps significantly.

This project aims to be the renderer part of the process; you have to write the server part yourself!

## Why?

For fun, and learning!


### Why MiniTileRenderer?

MiniTileRenderer aims to do one thing and one thing well (draw tiles), a la Mapserver. Forget tile servers that include logins, cors and caching. Those are better done by other services or your main application server.

Furthermore, I thought it'd be interesting to see what would happen if we allow other people to call the C code for the rendering directly from other languages. C is callable from a bunch of different languages (e.g. Python, C#) so it might be interesting to see what other people can make using it. It is almost impossible to cover all possible scenarios that a user of a tile server might want, so instead we make it easy for them to do it themselves, without having to worry about the drawing of the tiles. I intend to write some examples of this myself to demonstrate what's possible. 

For example, what if your data is completely static and unchanging, and you only want to render tiles within a small space; e.g. a single county of a country? The best option could be to generate WMTS tiles as `.png` files and store them in a structured folder hierarchy based on X Y and Z of the WMTS requests. Then its a simple case of serving out static files from disk/ cache/ CDN.

To generate tiles in this example, your best bet is probably to use Mapnik, which can be used in either "server" mode with some setup, or as a command line tool. Someone, somewhere on the internet might have done this, so you can probably find some bash/ Python script that you could copy paste... But setting up and figuring it all out would take weeks or months.

With MiniTileRenderer, we don't aim to provide this functionality out of the box, but we aim to make it easy to do so using your own scripts that you can tailor exactly to your needs.

Lets imagine another scenario. Say you're using Geoserver, and you want to edit the configuration programatically from a script. Some of this work can be done through the REST API that is baked in with it, but sometimes you need to edit config files directly. This can be difficult as the config is not meant to be human readable, and second, geoserver reads the config into memory (as far as I understand). MiniTileRenderer will aim to make it easy to do stuff like this by yourself by being easily scriptable.

### Why C?

- Speed and the size of the binary are important.
- Cairo graphics library is written in C. Most of the community around Cairo and samples online are written in C. There are Python bindings for it, but I can't find many examples for them.
- I love C# but System.Drawing isn't cross platform.

### Why toml?

From what I've read online, people don't like JSON or YAML. Also, personally I find XML ok when its written by machines, but I hate reading and writing it myself. I've been looking for a good configuration language, and wanted to give toml a try.

### Why spatialite?

It's easier to work with than ESRI shapefiles! GPKG might be interesting.

# Limitations 

- No support for coordinate systems. 
    * I'm wondering if we can get away with this by passing the coordinates directly to spatialite without checking them?
- No support for other vector data sources other than spatialite. POSTGIS support would be the best and easiest addition.
- No raster support. I'm not sure how to handle this one _well_.
- Only supports simple geometries (points, lines, polygons).
- Probably full of memory leaks and security issues.
- Text label support with automatic placement is in the pipeline.