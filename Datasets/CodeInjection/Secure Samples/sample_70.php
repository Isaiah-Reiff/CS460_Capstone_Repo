<?php
$action = $_POST['action'] ?? '';
$allowed = [
  'sum' => function($a){ return array_sum($a); },
  'count' => function($a){ return count($a); }
];
$vals = $_POST['vals'] ?? [];
if (!isset($allowed[$action]) || !is_array($vals)) { http_response_code(400); exit("bad"); }
echo $allowed[$action]($vals);
?>