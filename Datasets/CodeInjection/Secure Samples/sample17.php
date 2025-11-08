<?php
$tpl = $_GET['tpl'] ?? '';
$result = preg_replace_callback('/\{\{(\w+)\}\}/', function($m){
  $map = ['name'=>'Alice'];
  return $map[$m[1]] ?? '';
}, $tpl);
echo $result;
?>
