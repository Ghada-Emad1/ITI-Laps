<?php

use App\Http\Controllers\Api\PostController;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Models\User;
use Illuminate\Support\Facades\Hash;
use App\Models\Post;
use Illuminate\Validation\ValidationException;

Route::get('/user', function (Request $request) {
    return $request->user();
})->middleware('auth:sanctum');

// make the authanticaiton for users 
Route::middleware('auth:sanctum')->get('/posts',[PostController::class,'index']);
Route::post('/posts', [PostController::class, 'store']);
Route::get('/posts/{id}', [PostController::class, 'show']);


Route::post('/sanctum/token', function (Request $request) {

    $request->validate([

        'email' => 'required|email',

        'password' => 'required',

        'device_name' => 'required',

    ]);



    $user = User::where('email', $request->email)->first();



    if (! $user || ! Hash::check($request->password, $user->password)) {

        throw ValidationException::withMessages([

            'email' => ['The provided credentials are incorrect.'],

        ]);
    }



    return $user->createToken($request->device_name)->plainTextToken;
});