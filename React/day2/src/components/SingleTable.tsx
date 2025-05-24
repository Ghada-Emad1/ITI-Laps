import React from "react";

function SingleTable({ children, user }) {
  return (
    <>
     
      <td className="px-4 py-2">{user.name}</td>
      <td className="px-4 py-2">{user.email}</td>
      {children}
      
    </>
  );
}

export default SingleTable;
