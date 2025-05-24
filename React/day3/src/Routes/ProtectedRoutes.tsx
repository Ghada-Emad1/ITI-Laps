import useAuth from "../hooks/useAuth";
import { Navigate } from "react-router-dom";
import type { ReactNode } from "react";

interface ProtectedRoutesProps {
  children: ReactNode;
}

const ProtectedRoutes = ({ children }: ProtectedRoutesProps) => {
  const { email } = useAuth();
  
  if (!email) {
    return <Navigate to="/login"  />;
  }
  
  return <>{children}</>;
};

export default ProtectedRoutes;