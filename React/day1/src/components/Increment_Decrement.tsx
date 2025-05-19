import { useState } from 'react';

export function Increment_Decrement() {
  const [num, setNum] = useState(0);
  const incrementNum=()=>{
    setNum((num)=>num+1)
  }
  const decrementNum=()=>{
    if(num==0){
        num=0;
    }
    setNum((num)=>num-1)
  }
  return (
    <div className="flex justify-center items-center">
      <button onClick={incrementNum} className="cursor-pointer hover:opacity-[0.7] bg-green-800 text-white px-4 py-2 m-2 rounded">
        Increment
      </button>
      <p className="text-xl">Num : {num}</p>
      <button onClick={decrementNum} className=" cursor-pointer bg-red-700 hover:opacity-[0.7] text-white px-4 py-2 m-2 rounded">
        Decrement
      </button>
    </div>
  );
}
