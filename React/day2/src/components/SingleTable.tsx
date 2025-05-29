import type { ReactNode } from "react";
import React from "react";

type User = {
  name: string;
  email: string;
};

type SingleTableProps = {
  user: User;
  children?: ReactNode;
};

const SingleTable: React.FC<SingleTableProps> = ({ user, children }) => {
  return (
    <>
      <td className="px-4 py-2">{user.name}</td>
      <td className="px-4 py-2">{user.email}</td>
      {children}
    </>
  );
};

export default SingleTable;
