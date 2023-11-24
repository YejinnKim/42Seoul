<?php
define('DB_NAME', 'wordpress');
define('DB_USER', 'yejinkim');
define('DB_PASSWORD', '0000');
define('DB_HOST', 'mariadb');
define('DB_SOCKET', '/run/mysqld/mysqld.sock');
define('DB_CHARSET', 'utf8mb4');
define('DB_COLLATE', '');
define('FS_METHOD', 'direct');

$table_prefix = 'wp_';

define('WP_DEBUG', false);

if (!defined('ABSPATH')) {
    define('ABSPATH', __DIR__ . '/');
}

require_once ABSPATH . 'wp-settings.php';
