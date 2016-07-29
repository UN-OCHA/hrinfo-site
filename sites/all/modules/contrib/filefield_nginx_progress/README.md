# Filefield Nginx Progress

## Introduction 

This module provides support for an upload progress bar for a
backend/server implementing the
[RFC 1867](http://www.faqs.org/rfcs/rfc1867.html) upload using
multipart/form-data. Nginx does not yet support RFC 1867 uploads in
its suite of official modules. You can use the
[Upload](https://github.com/vkholodkov/nginx-upload-module) 3rd party
module to do that or just rely on PHP FastCGI support for RFC 1867.

## Drupal Requirements

 * For **drupal 6** the
   [filefield module](http://drupal.org/project/filefield) must be installed.
      
 * For **drupal 7** the file field is now a
   [core module](http://api.drupal.org/api/drupal/modules--file--file.module/7)
   and must be enabled. 

## Nginx Requirements 

 1. Using Nginx with a FastCGI backend, making use of the
    [FastCGI](http://wiki.nginx.org/HttpFcgiModule) module with the
    PHP backend.
    or using Nginx as a reverse proxy, making use of the
    [Proxy](http://wiki.nginx.org/HttpProxyModule) module.
  
 2. Use the 3rd party 
    [Upload Progress](https://github.com/masterzen/nginx-upload-progress-module)
    Nginx module.
    
    Build instructions are
    [here](http://wiki.nginx.org/HttpUploadProgressModule#Installation).
    
    Verify that the upload progress module is installed by issuing:
        
        nginx -V
        
    and check if there's a line with
    `--add-module=path/to/nginx-upload-progress-module`. If there is
    that means that the support for the upload progress bar is
    compiled in. Now you need to support the upload progress bar in
    the Nginx configuration.
    
## Upgrade from versions prior to 7.x-2.1 for Drupal 7
   
 Now it uses a pure JSON output. If you upgrade you must add
 `upload_progress_json_output` to the `/progress` location or the
 progress bar it won't work.
    
## Instalation 

 1. Install the module as usual from
    [drupal.org](https://drupal.org/project/filefield_nginx_progress).
    
 2. Add the support for the upload progress bar in your nginx
    configuration.
    
 3. Done.
 
## Nginx configuration

The configuration consists in three parts:

 1. Add a **zone** for **tracking** the uploads. This is a memory block
    used for storing the information regarding the upload that Nginx is
    proxying.
   
        ## Define a zone named uploads with a 1MB size.
        upload_progress uploads 1m;
       
    This is to be done at the `http` level of your config, meaning
    that it's the same for **all** vhosts configured on an instance of
    Nginx.
    
 2. Do a rewrite to support the way that the Nginx module reports the
    progress.
   
        ## The Nginx module wants ?X-Progress-ID query parameter so
        ## that it report the progress of the upload through a GET
        ## request. But the drupal form element makes use of clean
        ## URLs in the POST.
        location ~ (?<upload_form_uri>.*)/x-progress-id:(?<upload_id>\d*) {
           rewrite ^ $upload_form_uri?X-Progress-ID=$upload_id;
        }

        ## Now the above rewrite must be matched by a location that
        ## activates it and references the above defined upload
        ## tracking zone.
        locate ^~ /progress {
           upload_progress_json_output;
           report_uploads uploads;
        }
 
 3. Now on **each** location where you want the upload progress bar
    to work you must enable it like on this example.
     
    N.B. The `track_uploads` directive must be the **last** in a given
    location.
     
        location = /index.php {
           include fastcgi.conf;
           fastcgi_pass phpcgi;
           ## Track uploads for this location on the zone defined
           ## above with a 60 seconds timeout.
           track_uploads uploads 60s;
        }
         
 4. Reload your nginx configuration:
 
        service nginx reload
     
 5. Done.    
 
## TODO
 
 1. Suggest a configuration and verify it using a `hook_requirements()`.
     
## Credits & Acknowledgments

This module development is done by
[smoothify](http://drupal.org/user/115335) sponsored by the
[Spirit Library](http://spiritlibrary.com) and
[perusio](http://drupal.org/user/8859) &mdash; focusing on the D7 version.
