import { useState } from 'react';

export function ToDo() {
  const [todo, setTodo] = useState('');
  const [todos, setTodos] = useState<string[]>([]);

  const handleTodo = (e) => {
    setTodo(e.target.value);
  };

  const addTodo = () => {
    if(todo=='')return;
    setTodos([...todos, todo]);
    setTodo('');
  };
  const deleteTodo=(id)=>{
    setTodos(todos.filter((_,index)=>index!=id))
  }



  return (
    <div className="flex flex-col items-center justify-center h-[80vh] p-4">
      <h1 className="font-bold text-3xl text-yellow-600">Your To Do List</h1>
      
      <div className="mt-10 flex items-center gap-4">
        <input
          value={todo}
          onChange={handleTodo}
          type="text"
          className="px-4 py-2 w-60 rounded-lg border border-black"
        />
        <button
          onClick={addTodo}
          className="bg-blue-400 text-white rounded-lg px-6 py-2 cursor-pointer hover:bg-blue-500"
        >
          Add
        </button>
      </div>

      <div className="mt-10 w-full max-w-md space-y-4">
        {todos.map((item, index) => (
          <div
            key={index}
            className="flex justify-between items-center bg-gray-100 p-4 rounded-lg shadow"
          >
            <div className="flex gap-3 items-center">
              <span className="text-gray-600 font-semibold">{index + 1} </span>
              <h4 className="text-lg text-gray-800">{item}</h4>
            </div>
            <button
              
              onClick={()=>deleteTodo(index)}
              className="bg-red-600 text-white cursor-pointer px-4 py-2 rounded-lg hover:bg-red-700"
            >
              Delete
            </button>
          </div>
        ))}
      </div>
    </div>
  );
}
