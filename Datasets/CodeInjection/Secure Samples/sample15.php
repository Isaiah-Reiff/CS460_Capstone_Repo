<?php
$template = 'Hello {{name}}';
$name = htmlspecialchars($_GET['name'] ?? 'Guest', ENT_QUOTES, 'UTF-8');
echo str_replace('{{name}}', $name, $template);
?>
