#pragma once

#include <vector>

#include "Container.hpp"
#include "Frame.hpp"
#include "GameClock.hpp"

namespace Coronet
{
    template<class T> class Animation : public Container
    {
        // todo: add ctor with frames

        private:
            std::shared_ptr<GameClock> clock;
            std::vector<Frame<T>> frames;
            int currentFrameIndex = 0;
            int lastFrameIndex = -1;
            double currentFrameTicks = 0;

            void displayFrame(int index)
            {
                DisplayFrame(frames[index].GetContent());
            }

        protected:
            virtual void DisplayFrame(const T &frame) = 0;

            virtual void Load(DependencyManager &dependencies) override
            {
                Container::Load(dependencies);

                clock = dependencies.Get<GameClock>();
            }

        public:
            bool IsPlaying = false;
            bool Repeat = false;

            void AddFrame(Frame<T> frame)
            {
                frames.push_back(frame);
            }

            void AddFrame(T content, double duration)
            {
                AddFrame(Frame<T>(content, duration));
            }

            void AddFrames(std::vector<T> frames)
            {
                // todo: fix this??
                for (auto &f : frames)
                    this->frames.push_back(f);
            }

            void GoToFrame(int frameIndex)
            {
                int i = frameIndex;

                if (i < 0)
                    i = 0;
                else if (i >= frames.size())
                    i = frames.size() - 1;

                currentFrameIndex = i;
                currentFrameTicks = 0;
                displayFrame(currentFrameIndex);
            }

            void GoToLastFrame()
            {
                GoToFrame(frames.size() - 1);
            }

            void PlayOnce()
            {
                Repeat = false;
                IsPlaying = true;

                GoToFrame(0);
            }

            virtual void Update() override
            {
                Container::Update();

                if (IsPlaying && frames.size() > 0)
                {
                    currentFrameTicks += clock->GetElapsed();

                    double d = frames[currentFrameIndex].GetDuration();
                    while (currentFrameTicks > d)
                    {
                        currentFrameTicks -= d;
                        currentFrameIndex++;

                        if (currentFrameIndex >= frames.size())
                        {
                            if (Repeat)
                                currentFrameIndex = 0;
                            else
                            {
                                currentFrameIndex = frames.size() - 1;
                                IsPlaying = false;
                                break;
                            }
                        }
                    }

                    if (lastFrameIndex != currentFrameIndex)
                    {
                        lastFrameIndex = currentFrameIndex;
                        displayFrame(currentFrameIndex);
                    }
                }
            }
    };
}