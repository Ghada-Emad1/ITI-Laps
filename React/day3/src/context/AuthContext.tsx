/**provider & context 
 * provider : wrapper to service
 * context : 
 * value : is shared value i want to share between components
 */
import { createContext, useState} from "react";
import type { ReactNode } from "react";
// Define the shape of your context value
interface AuthContextType {
  email: string;
  setEmail: (email: string) => void;
}

// Create context with initial value (undefined) and type
export const AuthContext = createContext<AuthContextType | undefined>(undefined);

// Define props type for AuthProvider
interface AuthProviderProps {
  children: ReactNode;
}

export function AuthProvider({ children }: AuthProviderProps) {
  const [email, setEmail] = useState<string>('');
  console.log('Authprovider work')

  return (
    <AuthContext.Provider value={{ email, setEmail }}>
      {children}
    </AuthContext.Provider>
  );
}
