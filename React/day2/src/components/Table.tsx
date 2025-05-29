import { useState, useEffect } from "react";
import axios from "axios";
import SingleTable from "./SingleTable";

type User = {
  id: number;
  name: string;
  email: string;
  username: string;
};

function Table() {
  const [users, setUsers] = useState<User[]>([]);

  useEffect(() => {
    axios.get<User[]>("https://jsonplaceholder.typicode.com/users")
      .then((res) => setUsers(res.data))
      .catch((err) => console.error(err));
  }, []);

  return (
    <div className="bg-red-300 rounded-lg text-white flex justify-center flex-wrap gap-4 p-4">
      <table className="min-w-[600px] bg-white text-black rounded shadow-md overflow-hidden">
        <thead className="bg-gray-200">
          <tr>
            <th className="px-4 py-2 text-left">Name</th>
            <th className="px-4 py-2 text-left">Email</th>
            <th className="px-4 py-2 text-left">Username</th>
          </tr>
        </thead>
        <tbody>
          {users.map((user) => (
            <tr key={user.id} className="border-t">
              <SingleTable user={user}>
                <td className="px-4 py-2">{user.username}</td>
              </SingleTable>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default Table;
