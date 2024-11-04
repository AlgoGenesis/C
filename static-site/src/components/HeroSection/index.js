import clsx from 'clsx';
import { useState, useEffect } from 'react';
import Link from '@docusaurus/Link';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import styles from './styles.module.css';

const programmingLanguages = [
  {
    title: 'C',
    image: require('@site/static/img/C.png').default,
    description: 'C is a powerful and efficient programming language used for system programming, application development, and embedded systems.',
  },
  {
    title: 'C++',
    image: require('@site/static/img/cpp.png').default,
    description: 'C++ is a high-performance, compiled, general-purpose programming language that was developed by Bjarne Stroustrup as an extension of the C programming language.',
  },
  {
    title: 'Java',
    image: require('@site/static/img/java.webp').default,
    description: 'Java is a high-level, class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible.',
  },
];

function HeroSection() {
  const { siteConfig } = useDocusaurusContext();
  const [activeIndex, setActiveIndex] = useState(0);

  useEffect(() => {
    const intervalId = setInterval(() => {
      setActiveIndex((activeIndex + 1) % programmingLanguages.length);
    }, 5000);
    return () => clearInterval(intervalId);
  }, [activeIndex]);

  return (
    <div className={clsx('hero hero--primary', styles.heroBanner)}>
      <div className="container">
        <div className="row">
          {programmingLanguages.map((language, index) => (
            <div
              key={index}
              className={clsx(
                'col',
                styles.carouselItem,
                activeIndex === index ? styles.active : ''
              )}
            >
              <img src={language.image} alt={language.title} />
              <h2 className={styles.carouselTitle}>{language.title}</h2>
              <p className={styles.carouselDescription}>
                {language.description}
              </p>
              <Link
                className="button button--secondary button--lg"
                to="/docs/intro"
              >
                Learn More
              </Link>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}

export default HeroSection;

