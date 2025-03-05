<?php
class Validator
{
    public function validate($input)
    {
        return trim(htmlspecialchars($input));
    }

    public function validateCountry($country, &$errors)
    {
        $validCountries = ['Africa', 'South America', 'North America', 'Europe'];
        if (!in_array($country, $validCountries)) {
            $errors['country'] = "Invalid country selected.";
            return "";
        }
        return $country;
    }

    public function validateGender($gender, &$errors)
    {
        if (!in_array($gender, ["male", "female"])) {
            $errors['gender'] = "Invalid gender selected.";
            return "";
        }
        return $gender;
    }

    public function validatePassword($password, &$errors)
    {
        if (strlen($password) < 6) {
            $errors['password'] = "Password must be at least 6 characters long.";
        }
        return $password;
    }

    public function validateSkills($skills, &$errors)
    {
        if (empty($skills)) {
            $errors['skills'] = "Please select at least one skill.";
            return [];
        }
        return $skills;
    }
    public function validateImage($img, &$errors)
    {
        if ($img['size'] > 500000) {
            $errors['img'] = "Image file size should be less than 500KB.";
            return false;
        }

        $allowedTypes = ['image/jpg', 'image/jpeg', 'image/png', 'image/gif'];
        if (!in_array($img['type'], $allowedTypes)) {
            $errors['img'] = "Only JPG, PNG, and GIF files are allowed.";
            return false;
        }

        return true;
    }
}
