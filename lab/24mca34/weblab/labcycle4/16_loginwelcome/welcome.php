<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Welcome</title>
</head>
<body style="font-family: Arial, sans-serif; background-color: #f4f4f4; margin: 0; padding: 20px;">
    <h1 style="color: #333; text-align: center; border-bottom: 2px solid #ccc; padding-bottom: 10px;">
        Welcome, <?php echo htmlspecialchars($_SESSION['username']); ?>!
    </h1>
    <div style="text-align: center;">
        <a href="logout.php" style="display: inline-block; margin-top: 20px; padding: 10px 20px; background-color: #007BFF; color: white; text-decoration: none; border-radius: 5px;">
            Logout
        </a>
    </div>
</body>
</html>

