Utility-Image-Rebuild-module
============================

Drupal module - Utility Image Rebuild module

Drupal Core: 7.x

CONTENTS OF THIS FILE
=====================

* Introduction
* Installation

Introduction
============

Current Maintainer: Joseph Z (joseph@gotouch.com.au)

This module is a small utility tool.

It can help you rebuild the image(s) information in the image field within certain content type.

The two common cases are:

1. You replace the image(s) manually in server
such as cover.jpg from the small size to large size.
2. You update the image(s) path in database
such as from public://publication/1.jpg to public://article/01.jpg

In particular the {file_managed.filesize} and the {file_managed.timestamp}
columns will be incorrect.
And the image dimension in field_data_filename table will be incorrect as well.

This module can rebuild such information, then update them in database.


Installation
============

The Utility Image Rebuild module 
is dependent on two Drupal 7 core modules: file, image

Installation is quite simple,
Enable the module or you can use Drush: drush pm-enable utility_image_rebuild.
