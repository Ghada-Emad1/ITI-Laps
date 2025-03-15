<?php

namespace App\Http\Requests;

use Illuminate\Foundation\Http\FormRequest;
use Illuminate\Validation\Rule;

class UpdatePostRequest extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     */
    public function authorize(): bool
    {
        return true;
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array<string, \Illuminate\Contracts\Validation\ValidationRule|array<mixed>|string>
     */
    public function rules(): array
    {
        // dd($this->user_id);
        return [
            'title' => ['required', 'min:3', Rule::unique('posts', 'title')->ignore($this->user_id)],
            'description' => ['required', 'min:10'],
            'user_id' => ['required', 'exists:users,id']
        ];
    }


    public function messages(): array
    {
        return [
            'title.required' => 'A title is required.',
            'title.min' => 'The title must be at least 3 characters.',
            'description.required' => 'A description is required.',
            'description.min' => 'The description must be at least 10 characters.',
            'user_id.required' => 'A user ID is required.',
            'user_id.exists' => 'The user ID does not exist in the database.'
        ];
    }
}
