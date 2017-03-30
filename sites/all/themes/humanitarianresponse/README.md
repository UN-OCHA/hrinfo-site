# Humanitarian Response theme

## CSS

This project uses [Sass](http://sass-lang.com/) 

The Sass files are in `assets/sass`

### To generate the CSS from the Sass use [Compass](http://compass-style.org/):

1. Install Compass & other theme dependencies (requires Ruby): `bundle`

2. Watch for changes to the Sass: `compass watch`

3. Commit the generated CSS files with your other changes (it is not built on deploy).

## 'Powered by' operations

Operations (just Ethiopia intially) that are using the new 'Powered by' content have a set of styles for panels that overwrite the standard styles. This is done by adding the 'powered-by' class to the html tag on those pages and their child pages (clusters).

To apply the powered by styles to more operations add them to the poweredByPages array in [script.js](https://github.com/humanitarianresponse/site/blob/dev/sites/all/themes/humanitarianresponse/assets/javascripts/script.js#L9)
