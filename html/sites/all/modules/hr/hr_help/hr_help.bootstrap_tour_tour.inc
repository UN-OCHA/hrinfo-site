<?php
/**
 * @file
 * hr_help.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function hr_help_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'adding_content';
  $bootstrap_tour->title = 'Adding content';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'sandbox',
      'placement' => 'top',
      'title' => 'Adding content',
      'content' => '<p>Adding content to your space is very simple. Follow the steps !</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#block-hr-layout-hr-layout-create-links',
      'path' => '',
      'placement' => 'left',
      'title' => 'Click here',
      'content' => '<p>Click on the + sign and select the type of content that you want to add.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'Editing content',
      'content' => '<p>To edit content, simply navigate to the content you want to edit, and click on the "Edit" tab.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '',
      'path' => 'sandbox/content',
      'placement' => 'top',
      'title' => 'Viewing content',
      'content' => '<p>To find the content you want to edit, you can navigate directly within the space, or you can use this "Content" tab, to filter the content by type.</p>
<p>To keep learning how to manage a space, follow the <a href="/sandbox?tour=space_functionalities">Space Functionalities</a> site tour.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['adding_content'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'anatomy_of_a_space';
  $bootstrap_tour->title = 'Anatomy of a space';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'sandbox',
      'placement' => 'top',
      'title' => 'Anatomy of a space',
      'content' => '<p>This tour will show you how a space is structured and how it works, along with some special tips for space managers. Follow the steps !</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'Enter the Sandbox space',
      'content' => '<p>Here is the sandbox space, which allows you, as a space manager, to experiment functionalities without breaking anything on your own space. Let\'s see how it is structured.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#hr-space-tab',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Space tab',
      'content' => '<p>In this part of the screen, you will find the space tab. This tab tells your visitors in which space they are and allows them to go back to the space initial page at any time, but also gives them a dropdown menu to navigate back to the main sections of the site. The title of this tab is the same as the title of your space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#navigation',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Horizontal menu',
      'content' => '<p>The horizontal menu gives your visitors access to the different standard features provided by the space. These features can be activated or deactivated for each space.</p>
<p>Therefore, you can NOT customize this menu. The links are activated by enabling or disabling the features available for your space.</p>
<p>The layout and structure of these pages is standard amongst all spaces and can not be customized. The reason for this is to allow each visitor to find the same structure across all spaces.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#block-hr-notifications-hr-follow',
      'path' => '',
      'placement' => 'right',
      'title' => 'Follow button',
      'content' => '<p>The Follow button will allow your visitors, in the future, to receive email notifications every time a new content is added or edited within your space.</p>
<p>Currently, the follow button can be connected to Mailchimp to allow your visitors to subscribe to your Mailchimp list simply by clicking on this button.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#block-hr-layout-hr-layout-space-links',
      'path' => '',
      'placement' => 'right',
      'title' => 'Contact information',
      'content' => '<p>This part of the screen allows you to bring forward your social media (Facebook, Twitter etc...) and contact information (email), making it easy and clear to your visitors how to contact you.</p>
<p>Your space also comes with an <a href="http://www.digitaltrends.com/how-to/how-to-use-rss/">RSS feed</a>, which your visitors can use to follow you through their RSS reader.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#block-og-menu-og-single-menu-block',
      'path' => '',
      'placement' => 'right',
      'title' => 'Vertical menu',
      'content' => '<p>The vertical menu is yours. You can customize it in whatever way you want, adding whatever custom pages you wish. It will appear on all static pages of your space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'That\'s it !',
      'content' => '<p>That\'s it for this tour. To understand how to customize the different elements presented in this tour (ie social media links, Mailchimp, menu etc...), follow the <a href="/sandbox?tour=edit_tab">Edit tab</a> tour.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['anatomy_of_a_space'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'edit_tab';
  $bootstrap_tour->title = 'Edit tab';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#page-header .tabs',
      'path' => 'sandbox',
      'placement' => 'top',
      'title' => 'Edit tab',
      'content' => '<p>This tour will show you how to use the "Edit" tab of your space, in order to edit your space information.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#edit-title-field',
      'path' => 'sandbox/edit',
      'placement' => 'top',
      'title' => 'Space Title',
      'content' => '<p>You can change the space title here. If you do so however, remember that this will also change the title of the space tab that appears in the top left corner of the site.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-field-space-type',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space Type',
      'content' => '<p>You shouldn\'t need to change this. If you feel like you do, please write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> before.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#edit-field-space-category',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space category',
      'content' => '<p>You shouldn\'t need to change this. If you feel like you do, please write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> before.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-field-image',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space icon',
      'content' => '<p>You shouldn\'t need to change this. If you feel like you do, please write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> before.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#edit-og-menu',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space menu',
      'content' => '<p>You shouldn\'t need to change this. If you feel like you do, please write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> before.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#edit-og-roles-permissions',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space roles and permissions',
      'content' => '<p>You shouldn\'t need to change this. If you feel like you do, please write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> before.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '#edit-group-access',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space visibility',
      'content' => '<p>HumanitarianResponse gives you the possibility to have private and public spaces. Private spaces are only visible by members of the space. You shouldn\'t need to change this, however, if you want us to create a private space for you and your team at some point, please let us know by writing to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '#edit-body',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space body',
      'content' => '<p>Enter here some text that you would like to see on the home page of your space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    9 => array(
      'selector' => '#edit-field-website',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space Website',
      'content' => '<p>You shouldn\'t need to change this. If you feel like you do, please write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> before.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    10 => array(
      'selector' => '#edit-field-email',
      'path' => '',
      'placement' => 'top',
      'title' => 'Space Email',
      'content' => '<p>Enter here the contact email you wish to display for your space. This email will appear in the left hand side, above the vertical menu.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    11 => array(
      'selector' => '#edit-field-social-media',
      'path' => '',
      'placement' => 'top',
      'title' => 'Social media links',
      'content' => '<p>Enter here the links to your social media sites (Facebook, Twitter etc...). These links will automatically be converted to icons and will appear on the left hand side of your space, below the email.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    12 => array(
      'selector' => '#edit-field-mailchimp-api-key',
      'path' => '',
      'placement' => 'top',
      'title' => 'Mailchimp API key',
      'content' => '<p>Through this field, you can configure your space to automatically subscribe your visitors to your Mailchimp list whenever they click on the "Follow" button.</p>
<p>To create a Mailchimp API key, login to your Mailchimp account and go to "Account Settings", click on the "Extras" tab and select "API keys". Create an API key and paste it in this field.</p>
<p>Then, save your changes by clicking on the "Save" button at the bottom of this page, and <strong>come back</strong> to this Edit tab. You will see another field, which will allow you to select which Mailchimp list your followers should automatically be subscribed to.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    13 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'top',
      'title' => 'Save your changes',
      'content' => '<p>Finally, save your changes by clicking on this button.</p>
<p>To keep learning how to manage your space, follow the <a href="/sandbox?tour=adding_content">Adding content</a> site tour.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['edit_tab'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'i_can_not_login';
  $bootstrap_tour->title = 'I can not login';
  $bootstrap_tour->roles = '1';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'user/login',
      'placement' => 'top',
      'title' => 'You can not login ?',
      'content' => '<p>So, you have an account on Humanitarianresponse and, for some reason, you can not login ? Let\'s see if we can help you out.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'Have you registered ?',
      'content' => '<p>First, are you sure you have already registered ? If you didn\'t, then follow the tour <a href="/user/register?tour=registering_on_humanitarianresponse">Registering on Humanitarianresponse</a>. Otherwise, click "Next".</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '',
      'path' => 'user/password',
      'placement' => 'top',
      'title' => 'DId you forget your password ?',
      'content' => '<p>If you forgot your password, enter your email address in the textfield, and we will send you steps to recover it.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'Still can\'t login ?',
      'content' => '<p>If you still can not login after this, write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a>, and we will help you out.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['i_can_not_login'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'inside_a_space';
  $bootstrap_tour->title = 'Inside a space';
  $bootstrap_tour->roles = '';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => '<front>',
      'placement' => 'top',
      'title' => 'Inside a space',
      'content' => '<p>Each space provides different content, but follows the same layout. We will look in details, as an example, at the "ProCap" space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => 'topics/procap',
      'placement' => 'top',
      'title' => 'Enter the ProCap space',
      'content' => '<p>Here is the initial page of the ProCap page. Let\'s see how it is structured.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#hr-space-tab',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Space tab',
      'content' => '<p>In this part of the screen, you will find the space tab. This tab tells you in which space you are and allows you to go back to the space initial page at any time, but also gives you a dropdown menu to navigate back to the main sections of the site.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#navigation',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Horizontal menu',
      'content' => '<p>The horizontal menu gives you access to the different standard features provided by the space. These features can be activated or deactivated for each space, which is why you won\'t find the same set of features on each space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#block-hr-notifications-hr-follow',
      'path' => '',
      'placement' => 'right',
      'title' => 'Follow button',
      'content' => '<p>Each space provides a Follow button, which allows you (when you are registered on Humanitarianresponse), to be subscribed to the mailing list of the space, if the space has one.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#block-hr-layout-hr-layout-space-links',
      'path' => '',
      'placement' => 'right',
      'title' => 'Contact information',
      'content' => '<p>In this part of the screen, you will find the contact information for the space (email address, Facebook, Twitter etc...). Also, each space comes with an <a href="http://www.digitaltrends.com/how-to/how-to-use-rss/">RSS feed</a>, allowing you to easily follow the content of this space from your RSS reader.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#block-og-menu-og-single-menu-block',
      'path' => '',
      'placement' => 'right',
      'title' => 'Vertical menu',
      'content' => '<p>The vertical menu is different for each space, and provides links to pages within the space. This menu will appear on all pages within the space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'That\'s it !',
      'content' => '<p>That\'s it for this tour. Thanks for following !</p><p>If you are experiencing issues with the site, write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> and we will help you out.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['inside_a_space'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'introduction';
  $bootstrap_tour->title = 'Introduction';
  $bootstrap_tour->roles = '';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => '<front>',
      'placement' => 'top',
      'title' => 'Welcome to Humanitarianresponse ',
      'content' => '<p>Welcome !</p><p>If you would like to know how Humanitarianresponse works, and how to find content, this tour is for you. Simply follow the steps !</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'Spaces',
      'content' => '<p>Humanitarianresponse is built on what\'s called "spaces". A space is a collection of content (documents, news, events etc...) and people. Each space displays its own content, but using the same layout.</p><p>Let\'s see which spaces Humanitarianresponse has to offer.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '',
      'path' => 'operations',
      'placement' => 'top',
      'title' => 'Operations',
      'content' => '<p>Under operations, you will find the country and regional spaces. Each region or country will show you information about a specific country or region.</p><p>For now, we are still in the process of migrating our operational sites, so each operation points to a different website. However, as we move forward in this migration, each operational website will become a space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '',
      'path' => 'clusters',
      'placement' => 'top',
      'title' => 'Clusters',
      'content' => '<p>Under "Clusters", you will find links to the global cluster websites (for example, the global education cluster) and (still under construction) a map of the local clusters (for example, the education cluster in Mali). If you click on "Read all the information about Clusters", you will enter the Clusters space, which will give you textual information about clusters and how they work.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '',
      'path' => 'programme-cycle',
      'placement' => 'top',
      'title' => 'Programme Cycle',
      'content' => '<p>Under "Programme Cycle", you will find the spaces related to the Programme Cycle. This section is still under construction.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '',
      'path' => 'topics',
      'placement' => 'top',
      'title' => 'Topics',
      'content' => '<p>Under "Topics", you will find different spaces concerning the "Cross-cutting issues" or "Coordination". You will also find the IMWG group.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '',
      'path' => 'applications',
      'placement' => 'top',
      'title' => 'Applications',
      'content' => '<p>Applications are used by the field and by headquarters to find very specific data. This is where you will find the COD-FOD Registry, the Indicators Registry or the Toolbox. More will be coming soon...</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'top',
      'title' => 'That\'s it !',
      'content' => '<p>That\'s it for this tour. If you would like to know more about spaces and how they work, follow the <a href="/?tour=inside_a_space">Inside a space</a> tour.</p><p>If you are having issues with the site, write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a> and we will help you out.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['introduction'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'managing_a_space';
  $bootstrap_tour->title = 'Managing a space';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'sandbox',
      'placement' => 'top',
      'title' => 'How to manage a space ?',
      'content' => '<p>This tour will walk you through the different options you have when you are a manager of a space. Let\'s start with <a href="/sandbox?tour=anatomy_of_a_space">Anatomy of a space</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['managing_a_space'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'registering_on_humanitarianresponse';
  $bootstrap_tour->title = 'Registering on Humanitarianresponse';
  $bootstrap_tour->roles = '1';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'user/register',
      'placement' => 'top',
      'title' => 'Registering on Humanitarianresponse',
      'content' => '<p>This tour will help you to register on Humanitarianresponse. Simply follow the steps !</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#edit-mail',
      'path' => '',
      'placement' => 'top',
      'title' => 'Enter your email',
      'content' => '<p>Enter your email in this textfield. Please enter your professionnal email (for example your @un.org email).</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-profile-main-field-first-name',
      'path' => '',
      'placement' => 'top',
      'title' => 'Enter your name',
      'content' => '<p>Enter your first name and last name in these fields</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#edit-profile-main-field-organizations',
      'path' => '',
      'placement' => 'top',
      'title' => 'Select your organization',
      'content' => '<p>Select your organization in this field. If your organization does not appear, select "Other" and enter the name of your organization in the next field.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-profile-main-field-job-title',
      'path' => '',
      'placement' => 'top',
      'title' => 'Select your job title',
      'content' => '<p>Select your job title in this field. If your job title does not appear, select "Other" and enter your job title in the next field.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#edit-profile-main-field-location',
      'path' => '',
      'placement' => 'top',
      'title' => 'Select your location',
      'content' => '<p>Select the location you are based in. If the specific town/city you are based in does not appear, select the country.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#edit-profile-main-field-phones',
      'path' => '',
      'placement' => 'top',
      'title' => 'Enter your phone numbers',
      'content' => '<p>Enter your phone numbers in this field.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '#edit-profile-main-field-emails',
      'path' => '',
      'placement' => 'top',
      'title' => 'Enter your other emails',
      'content' => '<p>If you wish, enter your other email addresses in this field (personal email addresses for example)</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '#edit-profile-main-field-social-media',
      'path' => '',
      'placement' => 'top',
      'title' => 'Social media links',
      'content' => '<p>If you wish, enter the URLs of your social media profiles (LinkedIn, Facebook, Google Plus etc...) in this field.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    9 => array(
      'selector' => '#edit-timezone',
      'path' => '',
      'placement' => 'top',
      'title' => 'Timezone',
      'content' => '<p>Please select the timezone you usually work in. This is very important if you want to have the events of the site shown in your timezone !</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    10 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'top',
      'title' => 'Almost done !',
      'content' => '<p>You are almost done ! You just need to click on "Create new account". You will receive a confirmation email in your inbox with a link. Click on this link and you will be registered. Welcome to Humanitarianresponse !</p><p>If you are experiencing issues, write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a>, and we will help you out.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['registering_on_humanitarianresponse'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'space_functionalities';
  $bootstrap_tour->title = 'Space Functionalities';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'sandbox',
      'placement' => 'top',
      'title' => 'Space Functionalities',
      'content' => '<p>This tour will walk you through the different functionalities of a space, showing you how to edit menu items and how to add people to your space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => 'sandbox/group',
      'placement' => 'top',
      'title' => 'The Group Tab',
      'content' => '<p>From this tab, you can add people, select the features activated on your space or manage the menu items. Let\'s start with the "Features" page.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '',
      'path' => 'group/node/1506/admin/features',
      'placement' => 'top',
      'title' => 'Space features',
      'content' => '<p>From here you can enable or disable the features of your space. These features drive the menu item that your visitors will see in the horizontal menu of your space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '',
      'path' => 'sandbox/group',
      'placement' => 'top',
      'title' => 'Adding people',
      'content' => '<p>Let\'s see now how you can make people members of your space, by clicking the "Add people" link.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '',
      'path' => 'group/node/1506/admin/people/add-user',
      'placement' => 'top',
      'title' => 'Adding people',
      'content' => '<p>To add people as members of your space, select their username, chose their role (leave their role empty if they shouldn\'t have any role) and click on "Add users". This will effectively make them a member of your space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '',
      'path' => 'sandbox/people',
      'placement' => 'top',
      'title' => 'The People page',
      'content' => '<p>When you make people members of your space, they will show up to your visitors in the "People" page of your space, assuming you have activated this feature.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '',
      'path' => 'sandbox/group',
      'placement' => 'top',
      'title' => 'Managing people',
      'content' => '<p>Let\'s see now how you can manage the members of your space, by clicking the "People" link.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '',
      'path' => 'group/node/1506/admin/people',
      'placement' => 'top',
      'title' => 'Managing people',
      'content' => '<p>You can manage the members of your space from this page. Modify their roles, remove them from your space etc...</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '',
      'path' => 'sandbox/group',
      'placement' => 'top',
      'title' => 'Managing menu items',
      'content' => '<p>Let\'s see now how you can manage the vertical menu of your space, by clicking the "Menus" link.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    9 => array(
      'selector' => '',
      'path' => 'group/node/1506/admin/menus',
      'placement' => 'top',
      'title' => 'Managing the menu',
      'content' => '<p>From this page, you can manage the vertical menu that appears on the left hand side of your space. Add links, edit them, change the order in which they appear. To add a link, click on the "add link" link.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    10 => array(
      'selector' => '',
      'path' => 'group/node/1506/admin/menus/menu-og-1506/add',
      'placement' => 'top',
      'title' => 'Adding a menu link',
      'content' => '<p>To add a menu link, you will be presented with this form. From here you can enter the menu link title, its path and select a few options.</p>
<p>If you want to enter a menu item with no link (in order to separate your menu items), in the path field, enter <em>&lt;nolink&gt;</em> and make sure that you check the "Show as expanded" checkbox.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    11 => array(
      'selector' => '',
      'path' => 'sandbox/group',
      'placement' => 'top',
      'title' => 'That\'s it !',
      'content' => '<p>That\'s it for the space functionalities.</p> <p>You should now be able to manage your space menu, manage members within your space and enable/disable features. If you still have questions, feel free to write to <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['space_functionalities'] = $bootstrap_tour;

  return $export;
}
