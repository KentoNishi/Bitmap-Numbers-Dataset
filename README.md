# Bitmap Numbers Dataset

A dataset of labeled handwritten numbers for machine learning.

## About
This dataset contains manually labelled images of hand-written digits.
The root directory contains subdirectories for each labeled digit.
Every image is a bitmap, and the filenames are in the following format:
``
[image number].bmp
``
All images are resized to ``128x128``. The color depth is always 24 bit.

### Potential Issues
* The images were not taken at the ``128x128`` resolution, so scaling issues may occur.
    * Some scans did not originally have a 1:1 aspect ratio, so images may be slightly stretched.
* Some images are in color, while others are in monochrome.
    * The images were collected from different sources, so the colors may vary.
* Images may have artifacts.
    * Scans were converted from pdf to png, then to bmp. Some artifcats may appear.
* The image size may be too large.
    * ``128x128`` may be too large to train in a short amount of time.
        * You can easily convert these images to smaller sizes using command line tools such as [ImageMagick](https://www.imagemagick.org/).

## Credits
All samples from this dataset are from the public domain [numbers](https://github.com/kensanata/numbers) repository by [@kensanata](https://github.com/kensanata). The repository contains extra metadata such as country, gender, and age, as well as automatically categorized samples and other useful tools.
