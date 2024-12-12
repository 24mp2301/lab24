<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $age = $_POST['age']; // Ensure this matches the input field
    $class = $_POST['class'];

    echo "Name of student: $name <br> ID: $id <br> Age: $age <br> Class: $class";
}
?>

