<?php

require 'vendor/autoload.php';

/*
 * 1- VERB
 * 2- Resource //Products
 * 3- Resource ID
 * 4- Extra Params
 * 
 * 1- Validate
 */


$method = $_SERVER['REQUEST_METHOD'];

$urlParts = explode('/', $_SERVER['REQUEST_URI']);

$resource = $urlParts[2] ?? null;

$resourceID = $urlParts[3] ?? null;

header("Content-Type: application/json");

if ($resource !== 'products') {
    http_response_code(404);
    echo json_encode(["message" => "Resource $resource doesn't exist"]);
    exit;
}

$db = new MySQLHandler('products');

switch ($method) {
    case 'GET':
        if ($resourceID) {
            $data = $db->get_record_by_id($resourceID);
            if ($data && !empty($data)) {//array of rows
                echo json_encode($data[0]);
            } else {
                http_response_code(404);
                echo json_encode(['message' => 'Product not found']);
            }
            break;
        }
        $data = $db->get_data();
        echo json_encode($data);
        break;

    case 'POST':
        
        $valid = !empty($_POST['name']);
        if (!$valid) {
            http_response_code(400);
            echo json_encode(['message' => 'Validation errors']);
            break;
        }
        $success = $db->save($_POST);
        if ($success) {
            http_response_code(201);
            echo json_encode(['message' => 'Product created successfully']);
        } else {
            http_response_code(500);
            echo json_encode(['message' => 'Something went wrong']);
        }

        break;

    case 'PUT':
        if ($resourceID) {
            $_PUT  = json_decode(file_get_contents("php://input"), true);
            $valid = !empty($_PUT['name']);
            if (!$valid) {
                http_response_code(400);
                echo json_encode(['message' => 'Validation errors']);
                break;
            }
            $success = $db->update($_PUT, $resourceID);
            if ($success) {
                http_response_code(200);
                echo json_encode(['message' => 'Product updated successfully']);
            } else {
                http_response_code(500);
                echo json_encode(['message' => 'Something went wrong']);
            }
            break;
        }
        http_response_code(400);
        echo json_encode(['message' => 'Product id is required.']);

        break;

    case 'DELETE':
        if ($resourceID) {
            $db->delete($resourceID);
            break;
        }
        http_response_code(400);
        echo json_encode(['message' => 'Product id is required.']);

        break;

    default:
        http_response_code(405);
        echo json_encode(['message' => 'Method not allowed.']);
        break;
}


