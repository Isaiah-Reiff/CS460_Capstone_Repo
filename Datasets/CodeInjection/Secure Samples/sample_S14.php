<?php
$expr = $_POST['calc'] ?? "";

if (!preg_match('/^[\d+\-*/\s]+$/', $expr)) {
    http_response_code(400);
    echo "Invalid expression";
    exit;
}

$tokens = explode(' ', $expr);
if (count($tokens) === 3) {
    [$a, $op, $b] = $tokens;
    $a = floatval($a);
    $b = floatval($b);

    switch ($op) {
        case '+': $result = $a + $b; break;
        case '-': $result = $a - $b; break;
        case '*': $result = $a * $b; break;
        case '/': $result = $b != 0 ? $a / $b : "div-by-zero"; break;
        default:
            $result = "invalid op";
    }
} else {
    $result = "invalid format";
}

echo $result;
?>
