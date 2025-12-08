<?php
$template = $_GET['tpl'];
echo preg_replace('/\{\{(.+)\}\}/e', '$1', $template);
?>