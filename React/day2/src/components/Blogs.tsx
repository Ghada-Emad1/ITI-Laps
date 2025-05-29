import { useState, useEffect } from "react";
import axios from "axios";
import SingleBlog from "./SingleBlog";
const Blogs = () => {
  const [posts, setposts] = useState([]);
  const allPosts = () => {
    axios.get("https://jsonplaceholder.typicode.com/posts").then((res) => {
      console.log(res.data)
      setposts(res.data);
    });
  };
  useEffect(() => {
    allPosts();
  }, []);
  const showId = (id:number) => {
    console.log(id);
  };
  return (
    <div className="flex justify-center gap-6 flex-wrap p-6 bg-gray-50">
      {posts.map((post, index) => (
        <SingleBlog post={post} showId={showId} key={index} />
      ))}
    </div>
  );
};

export default Blogs;
