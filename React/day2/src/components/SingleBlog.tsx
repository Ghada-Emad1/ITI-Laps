type BlogPost = {
  id: number;
  title: string;
  body: string;
};

type SingleBlogProps = {
  post: BlogPost;
  showId: (id: number) => void;
};

const SingleBlog: React.FC<SingleBlogProps> = ({ post, showId }) => {
  return (
    <div className="w-80 bg-white rounded-xl shadow-lg p-4 border border-gray-200 hover:shadow-xl transition duration-300">
      <h2 className="text-xl font-semibold text-gray-800 mb-2">{post.title}</h2>
      <p className="text-gray-600">{post.body}</p>
      <button
        onClick={() => showId(post.id)}
        className="bg-purple-500 hover:bg-purple-600 px-6 py-2 text-white rounded-xl mt-4 transition duration-200"
      >
        Show ID
      </button>
    </div>
  );
};

export default SingleBlog;
