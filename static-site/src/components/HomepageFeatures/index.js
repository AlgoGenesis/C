import clsx from 'clsx';
import Heading from '@theme/Heading';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Progress of our project',
    Png: require('@site/static/assets/main.gif').default,
    description: (
      <>
        Our project consists of many different algorithms implemented in C. 
      </>
    ),
  },
];

function Feature({Svg, Png, title, description}) {
  return (
    <div className={clsx('col', styles.featureCenter)}>
      <div className="text--center">
        {Png ? <img src={Png} className={styles.featurePng} alt="Feature Icon" /> : <Svg className={styles.featureSvg} role="img" />}
      </div>
      <div className="text--center padding-horiz--md align-center display-block">
        <Heading as="h3">{title}</Heading>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
