<?php
$page = $_GET['page'] ?? 'home';
$routes = ['home' => 'home.php', 'about' => 'about.php'];
if (!isset($routes[$page])) { http_response_code(404); exit("not found"); }
include __DIR__ . '/pages/' . $routes[$page];
?>