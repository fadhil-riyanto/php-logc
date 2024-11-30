
# php logger

This library simply works like sprintf in C call.

## Installation

Install step

```bash
  git clone https://github.com/fadhil-riyanto/php-logc.git
  cd php-logc
  ./configure
  make -jN
  make install
```
    
nb: make sure you have build your own PHP, or just install php-dev version.

then just

```php
<?php
log_trace("fmt % #%", "abc", "8");
?>

```