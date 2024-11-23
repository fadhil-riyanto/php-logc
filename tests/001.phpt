--TEST--
Check if php_logger is loaded
--EXTENSIONS--
php_logger
--FILE--
<?php
echo 'The extension "php_logger" is available';
?>
--EXPECT--
The extension "php_logger" is available
