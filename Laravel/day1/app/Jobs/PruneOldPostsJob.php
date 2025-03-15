<?php

namespace App\Jobs;

use App\Models\Post;
use Carbon\Carbon;
use Illuminate\Contracts\Queue\ShouldQueue;
use Illuminate\Foundation\Bus\Dispatchable;
use Illuminate\Foundation\Queue\Queueable;
use Illuminate\Queue\InteractsWithQueue;
use Illuminate\Queue\SerializesModels;

class PruneOldPostsJob implements ShouldQueue
{
    use Queueable,Dispatchable,InteractsWithQueue,SerializesModels;

    /**
     * Create a new job instance.
     */
    public function __construct()
    {
        //
    }

    /**
     * Execute the job.
     */
    public function handle(): void
    {
        //
        $twoYearsAgo = Carbon::now()->subYears(2);
        Post::where('created_at', '<', $twoYearsAgo)->delete();
    }
}
