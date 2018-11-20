# OCHA Basic Drupal 7 starter theme

A minimal starter theme for OCHA sites built with Drupal 7. The markup and styles can also be used for non-Drupal sites.
### See [OCHA basic demo](https://ochabasic.demo.ahconu.org)

## For developers
See [OCHA basic dev site](https://ochabasic.dev.ahconu.org) for documentation and examples. View via web inspector to see Drupal template suggestions. This will help understand where the markup is coming from (some comes from Drupal, some is custom). This is especially relevant for implementations not using Drupal as the markup might be copied instead of used directly from the repo.

**Releases**

Refer to [Github releases](https://github.com/UN-OCHA/ocha_basic/releases) for latest updates. We use [npm-version](https://docs.npmjs.com/cli/version) and [sematantic versioning](https://semver.org/)


## This theme contains

* Common Header
* Common Footer
* Common SVG Icons
* Variables for breakpoints, colours, font-sizes, fonts, measurements and z-index
* Mixins for clearfix, REM font sizes and media queries
* Bootstrap dropdowns (requires jQuery 1.9.1 or higher)

**Optional components:**

* Grid (simplified version of Bootstrap v4 grid, https://v4-alpha.getbootstrap.com/layout/overview/)
* Typography
* Basic table styles
* Basic form styles
* gulp.js workflow for frontend development
  * Sass
  * Sourcemaps (see which specific Sass file contains styles during local development)
  * Autoprefixer
  * JS linting

## Integrations with other Drupal modules

* [jquery_update](https://www.drupal.org/project/jquery_update) — supports out Bootstrap library
* [Modernizr](https://www.drupal.org/project/modernizr) — centralized D7 API for modular Modernizr builds
* [PWA](https://www.drupal.org/project/pwa) — basic offline support and centralized API for manifest.json files

## Getting started

1. Copy this theme into your `sites/all/themes/custom` folder
2. If you want to renamne the theme, change the folder name, the filename of the .info file and find and replace for `ocha_basic` in the theme folder.
3. In the Drupal Admin, go to Appearance, find 'OCHA Basic Starter Theme' (or whatever you've renamed it to), and select **Enable and set default**

**To contribute to `ocha_basic` development:**

1. Install the dependencies: `npm install`
2. Copy `localConfig.example.json` to `localConfig.json` and specify the URL of your local Drupal environment.
3. Run the simple gulp task to build the CSS and watch for new changes: `gulp dev`
4. When you make commits, it will automatically run a "production" Sass build that excludes Sourcemaps


## CSS

This project uses [Sass](http://sass-lang.com/). To make changes edit the `.scss` files in the `sass/` folder, do NOT edit the files in `css/` directly.

Run `gulp dev` in the theme folder to have gulp watch for changes and automatically rebuild the CSS.

Preferably use Jenkins to run the Gulp task on build to generate the CSS. If this is possible on your project, add the `css/` folder to the `.gitignore` file and delete generated CSS from the repo.


## JS

Javascript files should be added to `js/` and to the scripts section of `ocha_basic.info`


## Icons

The available icons can be found in `img/icons`

There are two techniques used, depending on context.

1. SVG as a background-image value, usually on a pseudo element. The SVG fill colour is added as an attribute in the SVG file. We use this technique when using technique 2 isn't possible.
The icons are black by default. If you need another color, it's best to copy the icon and manually adjust the fill/stroke to suit your needs. Rename the copy to include the color in the filename eg. `arrow-down--white.svg`.

2. SVG symbol sprite using the `<use>` element. The SVG sprite is loaded as a single asset in the `html.tpl.php` before the closing body tag. Each icon within the sprite can be referenced by its ID eg. 
```
<svg class="icon icon--arrow-down">
  <use xlink:href="#arrow-down"></use>
</svg>
```
Each icon should have the class `icon` and a BEM selector if needed eg. `icon--arrow-down`. We can create associated CSS rules to control dimension and fill. We're using https://github.com/jkphl/gulp-svg-sprite. See https://una.im/svg-icons for more details.

### Generating the icons sprite
As defined in the gulp task, all new icons should be placed in the `img/icons` directory.
Run `gulp sprites` to generate a new sprite.
This generates the sprite SVG and places it in `img/icons/icons-sprite.svg` and it creates an html page with all SVGs for reference `img/icons/sprite.symbol.html`.


### Renaming icons
When importing a new version of the Common Icons, there is a bulk-renaming command in `package.json` that can be invoked by running the following:

```
# first, cd to repo root
npm run icon-rename
```

This assumes that you have a tool compatible with http://brewformulas.org/Rename — you can install it on OSX using Homebrew:

```
brew install rename
```



## Browser support

See https://un-ocha.github.io/styleguide/common-design/


## Favicons

OCHA default favicons are provided. Update these with your logo.

http://realfavicongenerator.net/ is a good tool for generating favicons.


## Modernizr

We support the [Modernizr Drupal module](https://www.drupal.org/project/modernizr) and the `ocha_basic.info` file contains the Modernizr tests we require.

After enabling the theme, go to `admin/configuration/development/modernizr` to rebuild Modernizr including the theme's feature detects: `svg`, `cssgrid`, `cssgridlegacy` and `mediaqueries`.


## Add to Homescreen / manifest.json

We support the [PWA Drupal module](https://www.drupal.org/project/pwa) instead of providing our own manifest.json file. The `hook_pwa_manifest_alter()` hook is implemented in `template.php` with our default colors/icons, which can be overridden using the normal PWA admin UI.


## Using with panels

Use with the Omega base theme to enable panels:

* Add `base theme = omega` to ocha_basic.info
* Create your layouts using page.tpl.php as a basis

