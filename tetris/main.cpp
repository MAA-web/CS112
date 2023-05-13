//#include "C:\Users\hithe\Downloads\New-folder\SDL2-devel-2.26.5-mingw\SDL2-2.26.5\i686-w64-mingw32\bin\SDL.dll"
#include "C:\Users\hithe\Downloads\New-folder\SDL2-devel-2.26.5-mingw\SDL2-2.26.5\x86_64-w64-mingw32\include\SDL2\SDL.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BLOCK_SIZE = 20;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int FRAME_RATE = 30;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event e;

class Block {
public:
    int x, y;
    int type;

    Block(int x, int y, int type) {
        this->x = x;
        this->y = y;
        this->type = type;
    }
};

vector<vector<int>> board(BOARD_HEIGHT, vector<int>(BOARD_WIDTH, 0));
vector<Block> current_blocks;

void init() {
    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(gRenderer);
    SDL_RenderPresent(gRenderer);
}

void close() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

vector<Block> rotate_blocks(vector<Block> blocks) {
    vector<Block> new_blocks;
    for (Block block : blocks) {
        // calculate new coordinates for each block
        int new_x = block.y;
        int new_y = -block.x;

        // adjust for rotation around center of the shape
        new_x += blocks[1].x;
        new_y += blocks[1].y;

        // add new block to vector
        new_blocks.push_back(Block(new_x, new_y, block.type));
    }
    return new_blocks;
}
void draw_block(int x, int y, int type) {
    SDL_Rect block_rect = { x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };

    switch (type) {
    case 1:
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        break;
    case 2:
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
        break;
    case 3:
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
        break;
    case 4:
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
        break;
    case 5:
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xFF, 0xFF);
        break;
    case 6:
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF);
        break;
    case 7:
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
    default:
        break;
    }

    SDL_RenderFillRect(gRenderer, &block_rect);
}
bool is_valid_move(vector<Block> blocks) {
    for (Block block : blocks) {
        if (block.x < 0 || block.x >= BOARD_WIDTH || block.y >= BOARD_HEIGHT || board[block.y][block.x] != 0) {
            return false;
        }
        else if (block.y < 0) {
            continue;
        }
    }

    return true;
}
void draw_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] != 0) {
                draw_block(j, i, board[i][j]);
            }
        }
    }
}

void draw_current_blocks() {
    for (Block block : current_blocks) {
        draw_block(block.x, block.y, block.type);
    }
}

  
     void spawn_block() {
            int block_type = rand() % 7 + 1;
                vector<Block> blocks;
            switch (block_type) {
            case 1:
                // I block
                blocks.push_back(Block(3, 0, block_type));
                blocks.push_back(Block(4, 0, block_type));
                blocks.push_back(Block(5, 0, block_type));
                blocks.push_back(Block(6, 0, block_type));
                break;
            case 2:
                // J block
                blocks.push_back(Block(4, 0, block_type));
                blocks.push_back(Block(4, 1, block_type));
                blocks.push_back(Block(4, 2, block_type));
                blocks.push_back(Block(3, 2, block_type));
                break;
            case 3:
                // L block
                blocks.push_back(Block(4, 0, block_type));
                blocks.push_back(Block(4, 1, block_type));
                blocks.push_back(Block(4, 2, block_type));
                blocks.push_back(Block(5, 2, block_type));
                break;
            case 4:
                // O block
                blocks.push_back(Block(4, 0, block_type));
                blocks.push_back(Block(5, 0, block_type));
                blocks.push_back(Block(4, 1, block_type));
                blocks.push_back(Block(5, 1, block_type));
                break;
            case 5:
                // S block
                blocks.push_back(Block(4, 1, block_type));
                blocks.push_back(Block(5, 1, block_type));
                blocks.push_back(Block(3, 2, block_type));
                blocks.push_back(Block(4, 2, block_type));
                break;
            case 6:
                // T block
                blocks.push_back(Block(3, 1, block_type));
                blocks.push_back(Block(4, 1, block_type));
                blocks.push_back(Block(5, 1, block_type));
                blocks.push_back(Block(4, 2, block_type));
                break;
            case 7:
                // Z block
                blocks.push_back(Block(3, 1, block_type));
                blocks.push_back(Block(4, 1, block_type));
                blocks.push_back(Block(4, 2, block_type));
                blocks.push_back(Block(5, 2, block_type));
                break;
            }

            if (is_valid_move(blocks)) {
                current_blocks = blocks;
            }
            else {
                // Game over
                close();
                exit(0);
            }
        }

        void add_blocks_to_board(vector<Block> blocks) {
            for (Block block : blocks) {
                board[block.y][block.x] = block.type;
            }
        }
        void generate_new_blocks() {
            srand(time(NULL));

            // Generate a random block type (1-7)
            int block_type = rand() % 7 + 1;

            // Initialize the block coordinates based on the block type
            vector<Block> new_blocks;
            switch (block_type) {
            case 1: // I block
                new_blocks.push_back(Block(3, 0, 1));
                new_blocks.push_back(Block(4, 0, 1));
                new_blocks.push_back(Block(5, 0, 1));
                new_blocks.push_back(Block(6, 0, 1));
                break;
            case 2: // J block
                new_blocks.push_back(Block(4, 0, 2));
                new_blocks.push_back(Block(4, 1, 2));
                new_blocks.push_back(Block(5, 1, 2));
                new_blocks.push_back(Block(6, 1, 2));
                break;
            case 3: // L block
                new_blocks.push_back(Block(6, 0, 3));
                new_blocks.push_back(Block(4, 1, 3));
                new_blocks.push_back(Block(5, 1, 3));
                new_blocks.push_back(Block(6, 1, 3));
                break;
            case 4: // O block
                new_blocks.push_back(Block(4, 0, 4));
                new_blocks.push_back(Block(5, 0, 4));
                new_blocks.push_back(Block(4, 1, 4));
                new_blocks.push_back(Block(5, 1, 4));
                break;
            case 5: // S block
                new_blocks.push_back(Block(5, 0, 5));
                new_blocks.push_back(Block(6, 0, 5));
                new_blocks.push_back(Block(4, 1, 5));
                new_blocks.push_back(Block(5, 1, 5));
                break;
            case 6: // T block
                new_blocks.push_back(Block(4, 0, 6));
                new_blocks.push_back(Block(5, 0, 6));
                new_blocks.push_back(Block(6, 0, 6));
                new_blocks.push_back(Block(5, 1, 6));
                break;
            case 7: // Z block
                new_blocks.push_back(Block(4, 0, 7));
                new_blocks.push_back(Block(5, 0, 7));
                new_blocks.push_back(Block(5, 1, 7));
                new_blocks.push_back(Block(6, 1, 7));
                break;
            }

            // Check if the new blocks overlap with existing blocks
            if (!is_valid_move(new_blocks)) {
                // Game over
                close();
                exit(0);
            }

            // Set the new blocks as the current blocks
            current_blocks = new_blocks;
        }

        void handle_input() {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    close();
                    exit(0);
                }
                else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        // Move left
                    {
                        vector<Block> new_blocks;
                        for (Block block : current_blocks) {
                            Block new_block(block.x - 1, block.y, block.type);
                            new_blocks.push_back(new_block);
                        }
                        if (is_valid_move(new_blocks)) {
                            current_blocks = new_blocks;
                        }
                        break;
                    }
                    case SDLK_RIGHT:
                        // Move right
                    {
                        vector<Block> new_blocks;
                        for (Block block : current_blocks) {
                            Block new_block(block.x + 1, block.y, block.type);
                            new_blocks.push_back(new_block);
                        }
                        if (is_valid_move(new_blocks)) {
                            current_blocks = new_blocks;
                        }
                        break;
                    }
                    case SDLK_DOWN:
                        // Move down
                    {
                        vector<Block> new_blocks;
                        for (Block block : current_blocks) {
                            Block new_block(block.x, block.y + 1, block.type);
                            new_blocks.push_back(new_block);
                        }
                        if (is_valid_move(new_blocks)) {
                            current_blocks = new_blocks;
                        }
                        else {
                            add_blocks_to_board(current_blocks);
                            current_blocks.clear();
                            generate_new_blocks();
                        }
                        break;
                    }
                    case SDLK_UP:
                        // Rotate
                    {
                        vector<Block> new_blocks = rotate_blocks(current_blocks);
                        if (is_valid_move(new_blocks)) {
                            current_blocks = new_blocks;
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }


        void update() {
            static int frame_count = 0;
            static int drop_speed = 20;

            if (frame_count % drop_speed == 0) {
                vector<Block> new_blocks = current_blocks;
                for (Block& block : new_blocks) {
                    block.y += 1;
                }

                if (is_valid_move(new_blocks)) {
                    current_blocks = new_blocks;
                }
                else {
                    add_blocks_to_board(current_blocks);
                    generate_new_blocks();
                }
            }

            frame_count++;

            draw_board();
            draw_current_blocks();
            SDL_RenderPresent(gRenderer);
        }

        void render() {
            SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(gRenderer);
            draw_board();
            draw_current_blocks();
            SDL_RenderPresent(gRenderer);
        }

        int main(int argc, char* args[]) {
            srand(time(NULL));
            init();

            generate_new_blocks();

            bool quit = false;
            while (!quit) {
                handle_input();
                update();
                render();
                SDL_Delay(1000 / FRAME_RATE);
            }

            close();
            return 0;
        }