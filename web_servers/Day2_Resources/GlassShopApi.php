<?php
require './vendor/autoload.php';
header("Content-Type: application/json");


$method = $_SERVER['REQUEST_METHOD'];
$urlParts = explode('/', trim($_SERVER['REQUEST_URI'], '/'));

$resource = $urlParts[1] ?? null;  
$resourceID = $urlParts[2] ?? null;  

if ($resource !== 'items') {
    http_response_code(404);
    echo json_encode(["error" => "Resource doesn't exist"]);
    exit;
}


$db = new MySQLHandler('items');

switch ($method) {
    case 'GET':
        if ($resourceID) {
            $data = $db->get_record_by_id($resourceID);
            if ($data && !empty($data)) {
                echo json_encode($data[0]);
            } else {
                http_response_code(404);
                echo json_encode(["error" => "Resource not found"]);
            }
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
            echo json_encode(["status" => "Resource created successfully"]);
        } else {
            http_response_code(500);
            echo json_encode(["error" => "Internal server error"]);
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
                     
                   
                    echo json_encode(['message' => 'Item updated successfully']);
                } else {
                    http_response_code(500);
                    echo json_encode(['message' => 'Something went wrong']);
                }
                break;
            }
            http_response_code(400);
            echo json_encode(['message' => 'Item id is required.']);
    
            break;

            case 'DELETE':
                if (!$resourceID) {
                    http_response_code(400);
                    echo json_encode(["error" => "Bad request"]);
                    break;
                }
                
                $success= $db->delete($resourceID);
                
                if ($success) {
                    echo json_encode(["status" => "Resource was deleted successfully!"]);
                } else {
                    http_response_code(500);
                    echo json_encode(["error" => "internal server error!"]);
                }
                break;
        
            default:
                http_response_code(405);
                echo json_encode(['message' => 'Method not allowed.']);
                break;
}
