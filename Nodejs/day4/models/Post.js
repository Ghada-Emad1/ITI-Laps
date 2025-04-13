const mongoose = require("mongoose");

const { Schema } = mongoose;

const commentSchema = new Schema({
  text: {
    type: String,
    required: true,
  },
  author: {
    type: Schema.Types.ObjectId,
    ref: "User",
   required: true,
  },
  date: {
    type: Date,
    default: Date.now,
  },
});
const postSchema = new Schema(
    {
        title: {
            type: String,
            required: true,
        },
        content: {
            type: String,
            required: true,
        },
        author: {
            type: Schema.Types.ObjectId,
            ref: "User",
        },
        tags: [String],
        comments: [commentSchema],
        likes: [{
            type: Schema.Types.ObjectId,
            ref:'User'
    }]
  },
  {
    timestamps: true,
  }
);


module.exports = mongoose.model("Post", postSchema);
