// Node/Gulp Utilities
const gulp = require('gulp');
const log = require('fancy-log');
const c = require('chalk');
const plumber = require('gulp-plumber');
const spawn = require('child_process').spawn;
const gulpif = require('gulp-if');
const svgSprite = require('gulp-svg-sprite');


// Development Tools
const bs = require('browser-sync');
const reload = bs.reload;
const rename = require('gulp-rename');
const sass = require('gulp-sass');
const cssnano = require('cssnano');
const postcss = require('gulp-postcss');
const prefix = require('autoprefixer');
const sourcemaps = require('gulp-sourcemaps');
const jshint = require('gulp-jshint');
const stylish = require('jshint-stylish');
const uglify = require('gulp-uglify');
const taskListing = require('gulp-task-listing');
const changed = require('gulp-changed');
const concat = require('gulp-concat');


//——————————————————————————————————————————————————————————————————————————————
// Load local environment config
//——————————————————————————————————————————————————————————————————————————————
let localConfig;
try {
  localConfig = require('./localConfig.json');
}
catch (err) {
  if (process.env.NODE_ENV !== 'production') {
    log(c.bgRed.white('localConfig.json is missing'));
    log(c.red('Copy localConfig.example.json to localConfig.json and configure for your Drupal environment.'));
  }
}


//——————————————————————————————————————————————————————————————————————————————
// Debug info
//——————————————————————————————————————————————————————————————————————————————
if (process.env.NODE_ENV === 'production') {
  log(c.bgYellow.black('Production'), c.yellow('environment detected'));
} else {
  log(c.bgYellow.black('Local'), c.yellow('environment detected'));
}


//——————————————————————————————————————————————————————————————————————————————
// BrowserSync
//——————————————————————————————————————————————————————————————————————————————
gulp.task('dev:bs', () => {
  bs({
    proxy: localConfig.drupalUrl,
    open: false,
    port: '3000',
  });
});


//——————————————————————————————————————————————————————————————————————————————
// Sass
//——————————————————————————————————————————————————————————————————————————————
gulp.task('dev:sass', () => {
  bs.notify(`Compiling Sass...`);

  return gulp.src(['sass/styles.scss'])
    .pipe(plumber())
    .pipe(gulpif(process.env.NODE_ENV !== 'production', sourcemaps.init()))
    .pipe(sass({outputStyle: 'nested'}).on('error', sass.logError))
    .pipe(postcss([
      prefix({
        browsers: ['>1%', 'iOS 9'],
        cascade: false,
      }),
      cssnano(),
    ]))
    .pipe(gulpif(process.env.NODE_ENV !== 'production', sourcemaps.write('./')))
    .pipe(gulp.dest('css/'))
    .pipe(reload({stream: true}));
});

//——————————————————————————————————————————————————————————————————————————————
// SVG Sprite generation
//——————————————————————————————————————————————————————————————————————————————

// SVG Config
var SVGconfig = {
  mode: {
    symbol: { // symbol mode to build the SVG
      dest: 'img/icons', // destination folder
      sprite: 'icons-sprite.svg', //sprite name
      example: true // Build sample page
    }
  },
  svg: {
    xmlDeclaration: false, // strip out the XML attribute
    doctypeDeclaration: false // don't include the !DOCTYPE declaration
  }
};

gulp.task('sprite-page', function() {
  return gulp.src('img/icons/*.svg')
    .pipe(svgSprite(SVGconfig))
    .pipe(gulp.dest('.'));
});

gulp.task('sprites', ['sprite-page']);

//——————————————————————————————————————————————————————————————————————————————
// JS Linting
//——————————————————————————————————————————————————————————————————————————————
// gulp.task('dev:js-lint', () => {
//   return gulp.src('js/*.js')
//     .pipe(jshint())
//     .pipe(jshint.reporter(stylish));
// });


//——————————————————————————————————————————————————————————————————————————————
// JS Bundling
//——————————————————————————————————————————————————————————————————————————————
// gulp.task('dev:js-bundle', () => {
//   return gulp.src([
//       'js/*.js',
//     ])
//     .pipe(concat('ocha_bundle.js'))
//     .pipe(gulpif(process.env.NODE_ENV === 'production', uglify()))
//     .pipe(gulp.dest('js'))
//     .pipe(reload({stream: true}));
// });

//——————————————————————————————————————————————————————————————————————————————
// JS Lint + Bundle
//——————————————————————————————————————————————————————————————————————————————
// gulp.task('dev:js', ['dev:js-lint', 'dev:js-bundle']);


//——————————————————————————————————————————————————————————————————————————————
// Build assets and start Browser-Sync
//——————————————————————————————————————————————————————————————————————————————
gulp.task('dev', ['dev:sass', /*'dev:js',*/ 'dev:bs', 'watch']);


//——————————————————————————————————————————————————————————————————————————————
// Watch Files For Changes
//——————————————————————————————————————————————————————————————————————————————
gulp.task('watch', () => {
  // gulp.watch(['js/*.js'], ['dev:js']);
  gulp.watch(['sass/**/*.scss'], ['dev:sass']);
});


//——————————————————————————————————————————————————————————————————————————————
// Build all assets in the theme
//——————————————————————————————————————————————————————————————————————————————
gulp.task('build', ['dev:sass', /*'dev:js'*/]);


//——————————————————————————————————————————————————————————————————————————————
// Offer help on command line
//——————————————————————————————————————————————————————————————————————————————
gulp.task('help', taskListing);


//——————————————————————————————————————————————————————————————————————————————
// Help task is default
//——————————————————————————————————————————————————————————————————————————————
gulp.task('default', ['help']);
