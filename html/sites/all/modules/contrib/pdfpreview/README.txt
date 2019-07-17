This module lets you show a preview of PDF files uploaded via fields.
This module uses ImageMagick to extract the first page of a PDF file to a JPEG
image which is used as PDF preview link to the file. 
You can select any image style for the PDF preview image link.
PDFPreview extracts only the first page and uses it as link to PDF file or to
the content where is attached. The images are stored on a configurable folder
inside your files folder, so it's fully compatible with multisite installations.
If the image is missing at display moment, it will be created.

- Usage:
Install like any other module and enable it. Go to 'Manage Display' page for your
content type and select 'PDFPreview' as formatter of a file field. Use the config
button to display formatter settings, and configure it as you wish.
You can go to admin/settings/media/pdfpreview to set up the extraction path, image
quality and dimensions for the extracted images.

 - Requisites:
Image module with ImageMagick toolkit enabled and configured. Is not
necessary to be set as default toolkit. 
