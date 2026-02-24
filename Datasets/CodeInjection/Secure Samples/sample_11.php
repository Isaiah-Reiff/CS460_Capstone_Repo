<?php
$handlers = [
    "add" => function($a, $b) { return $a + $b; },
    "subtract" => function($a, $b) { return $a - $b; },
    "concat" => function($a, $b) { return $a . $b; }
];

$action = $_POST['action'] ?? "";
$params = $_POST['params'] ?? [];

if (!is_array($params) || count($params) !== 2) {
    http_response_code(400);
    echo "Invalid parameters";
    exit;
}

if (array_key_exists($action, $handlers)) {
    $result = $handlers[$action]($params[0], $params[1]);
    echo htmlspecialchars((string)$result, ENT_QUOTES, 'UTF-8');
} else {
    http_response_code(400);
    echo "Unsupported action";
}
?>