<?php
$validators = [
    "len" => function($x) { return strlen($x); },
    "alpha" => function($x) { return ctype_alpha($x) ? "OK" : "FAIL"; }
];

$key = $_GET['validator'] ?? "";

if (!array_key_exists($key, $validators)) {
    http_response_code(400);
    echo "Invalid validator";
    exit;
}

$fn = $validators[$key];

echo $fn("test");
?>