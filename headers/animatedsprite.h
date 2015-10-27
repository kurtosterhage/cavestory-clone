/*
 * AnimatedSprite class
 * Holds logic for animating sprites
 */

#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include "globals.h"
#include <map>
#include <string>
#include <vector>

class Graphics;

class AnimatedSprite: public Sprite {
    public:
        AnimatedSprite();
        AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX,
                       int sourceY, int width, int height, float posX, float posY,
                       float timeToUpdate);

        /*
         * void playAnimation
         * Plays the animation provided if it's not already playing
         */
        void playAnimation(std::string animation, bool once = false);

        /*
         * void update
         * Updates the animated sprites
         */
        void update(int elapsedTime);

        /*
         * void draw
         * Draws the sprites to the screen
         */
        void draw(Graphics &graphics, int x, int y);

    protected:
        double _timeToUpdate;
        bool _currentAnimationOnce;
        std::string _currentAnimation;

        /*
         * void addAnimation
         * Adds an animation to the map of animations for the sprites
         */
        void addAnimation(int frames, int x, int y, std::string name, int width,
                          int height, Vector2 offset);

        /*
         * void resetAnimations
         * Resets all animations associated with this sprites
         */
        void resetAnimations();

        /*
         * void stopAnimation
         * Stops the current animation
         */
        void stopAnimation();

        /*
         * void setVisible
         * Changes the visibility of the animated sprites
         */
        void setVisible(bool visible);

        /*
         * void animationDone
         * Logic that happens when an animation ends
         */
        virtual void animationDone(std::string currentAnimation) = 0;

        /*
         * void setupAnimations
         * A required function that sets up all animations for a sprites
         */
        virtual void setupAnimations() = 0;

    private:
        std::map<std::string, std::vector<SDL_Rect>> _animations;
        std::map<std::string, Vector2> _offsets;

        int _frameIndex;
        double _timeElapsed;
        bool _visible;
};

#endif //ANIMATED_SPRITE_H